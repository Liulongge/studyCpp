#include <iostream>
#include <map>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <mutex>

using namespace std;

#define GEN_COUNT 10

typedef struct _alarm_info_t
{
    uint64_t ts = 0;
    uint64_t id = 0;
    uint64_t info = 0;
    uint64_t rsv = 0;
} alarm_info_t;

class FaultDiagnosis
{
public:
    FaultDiagnosis(/* args */){};
    ~FaultDiagnosis() {
        last_alarm_infos_.clear();
        cur_alarm_infos_.clear();

    };
    void analysis(void);
    void genAlarm(int i);
private:

    void reportAlarm(alarm_info_t *alarm_info);
    
    std::map<int, alarm_info_t> last_alarm_infos_;
    std::map<int, alarm_info_t> cur_alarm_infos_;
    std::vector<int> need_clear_alarm_infos_;
    std::vector<int> need_report_alarm_infos_;
    std::mutex mtx_; // 创建一个互斥量
};

void FaultDiagnosis::reportAlarm(alarm_info_t *alarm_info)
{
    std::unique_lock<std::mutex> lock(mtx_); // 创建一个智能锁实例，自动锁定互斥量
    cur_alarm_infos_[alarm_info->id] = *alarm_info;
    lock.unlock(); // 手动解锁
}

void FaultDiagnosis::genAlarm(int i)
{
    cur_alarm_infos_.clear();
    alarm_info_t alarm_info;
    switch (i){
        case 0: {
            alarm_info.id = 1;
            reportAlarm(&alarm_info);
            alarm_info.id = 2;
            reportAlarm(&alarm_info);
            alarm_info.id = 3;
            reportAlarm(&alarm_info);
            break;
        }
        case 1: {
            alarm_info.id = 1;
            reportAlarm(&alarm_info);
            alarm_info.id = 4;
            reportAlarm(&alarm_info);
            alarm_info.id = 5;
            reportAlarm(&alarm_info);
            break;
        }
        case 2: {
            ;
            break;
        }
        case 3: {
            alarm_info.id = 1;
            reportAlarm(&alarm_info);
            alarm_info.id = 4;
            reportAlarm(&alarm_info);
            alarm_info.id = 6;
            reportAlarm(&alarm_info);
            break;
        }
        case 4: {
            alarm_info.id = 1;
            reportAlarm(&alarm_info);
            alarm_info.id = 2;
            reportAlarm(&alarm_info);
            alarm_info.id = 3;
            reportAlarm(&alarm_info);
            break;
        }
        case 5: {
            break;
        }
        case 6: {
            break;
        }
        case 7: {
            alarm_info.id = 1;
            reportAlarm(&alarm_info);
            alarm_info.id = 1;
            reportAlarm(&alarm_info);
            alarm_info.id = 1;
            reportAlarm(&alarm_info);
            break;
        }
        case 8: {
            alarm_info.id = 2;
            reportAlarm(&alarm_info);
            alarm_info.id = 10;
            reportAlarm(&alarm_info);
            alarm_info.id = 11;
            reportAlarm(&alarm_info);
            break;
        }
        case 9: {
            alarm_info.id = 2;
            reportAlarm(&alarm_info);
            alarm_info.id = 2;
            reportAlarm(&alarm_info);
            alarm_info.id = 2;
            reportAlarm(&alarm_info);
            break;
        }
    }
}

void FaultDiagnosis::analysis(void)
{
    need_clear_alarm_infos_.clear();
    need_report_alarm_infos_.clear();

    cout << "map currtnt \t: ";
    for (auto &tmp : cur_alarm_infos_)
    {
        cout << tmp.first << " ";
    }
    cout << endl;

    cout << "map last \t: ";
    for (auto &tmp : last_alarm_infos_)
    {
        cout << tmp.first << " ";
    }
    cout << endl;

    for (const auto &kv1 : last_alarm_infos_) {
        if (cur_alarm_infos_.find(kv1.first) == cur_alarm_infos_.end()) {
            need_clear_alarm_infos_.push_back(kv1.first);
        }
    }

    for (const auto &kv1 : cur_alarm_infos_) {
        if (last_alarm_infos_.find(kv1.first) == last_alarm_infos_.end()) {
            need_report_alarm_infos_.push_back(kv1.first);
        }
    }

    cout << "需要上报的key有: ";
    for (auto &tmp : need_report_alarm_infos_) {
        cout << tmp << " ";
    }

    cout << ", 需要清空的key有: ";
    for (auto &tmp : need_clear_alarm_infos_) {
        cout << tmp << " ";
    }
    cout << endl;

    last_alarm_infos_ = std::move(cur_alarm_infos_); /* 移动构造更为高效 */
}

int main(int argc, char *argv[])
{
    int tmp = 0;
    FaultDiagnosis *fault_diagnosis = new FaultDiagnosis();
    for (int i = 0; i < GEN_COUNT; i++)
    {
        fault_diagnosis->genAlarm(i);

        fault_diagnosis->analysis();
        cout << endl;
    }

    return 0;
}
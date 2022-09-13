/* standard lib */
#include <stdio.h>
#include "stdlib.h"
#include "math.h"

int target_floor_number = 8;
int current_floor_number = 1;
int accumulated_floor_number = 0;
#define TOP_FLOOR 9
#define BOTTOM_FLOOR 1

/* event array and enum below must be in sync! */
typedef enum
{ 
    _idle = 0, _goingUp = 1, _goingDown = 2, _AtTop = 3, _AtBottom = 4,  _malfunction = 5, _unexpected = 6, _end = 7 
} state_codes_e;

typedef enum
{
    up = 0, down = 1, halt = 2, top = 3, bottom = 4, fail = 5, quit = 6 
} ret_codes_e;

int event_idle(void)
{
    printf("Idle!\n");
    printf("Input target floor number in [1, 9] (which floor you want to go?): \n");
    scanf("%d", &target_floor_number);

    if(current_floor_number < target_floor_number)
        return up;
    else if(current_floor_number > target_floor_number)
        return down;
    else if(current_floor_number == target_floor_number)
        return halt;
    else
        return fail;
}

int event_goingUp(void)
{
    current_floor_number += 1;
    accumulated_floor_number += 1;
    printf("Going up! Floor number is %d\n", current_floor_number);

    if(accumulated_floor_number > 100)
        return fail;
    else if(TOP_FLOOR == current_floor_number)
        return top;
    else if(BOTTOM_FLOOR == current_floor_number)
        return bottom;
    else if(current_floor_number < target_floor_number)
        return up;
    else if(current_floor_number == target_floor_number)
        return halt;
    else
        return quit;
}

int event_goingDown(void)
{
    current_floor_number -= 1;
    accumulated_floor_number += 1;
    printf("Going down! Floor number is %d\n", current_floor_number);

    if(accumulated_floor_number > 100)
        return fail;
    else if(TOP_FLOOR == current_floor_number)
        return top;
    else if(BOTTOM_FLOOR == current_floor_number)
        return bottom;
    else if(current_floor_number > target_floor_number)
        return down;
    else if(current_floor_number == target_floor_number)
        return halt;
    else
        return quit;
}

int event_atTop(void)
{
    printf("At top! current_floor_number= %d\n", current_floor_number);
    printf("Input target floor number in [1, 9] (which floor you want to go?): \n");
    scanf("%d", &target_floor_number);

    if(current_floor_number > target_floor_number)
        return down;
    else if(current_floor_number == target_floor_number)
        return halt;
    else
        return fail;
}

int event_atBottom(void)
{
    printf("At Bottom! current_floor_number= %d\n", current_floor_number);
    printf("Input target floor number in [1, 9] (which floor you want to go?): \n");
    scanf("%d", &target_floor_number);

    if(current_floor_number < target_floor_number)
        return up;
    else if(current_floor_number == target_floor_number)
        return halt;
    else
        return fail;
}

int event_malfunction(void)
{
    printf("Elevator needs maintanence!\n");
    printf("accumulated_floor_number = %d\n", accumulated_floor_number);
    return quit;
}

int event_end(void)
{
    printf("Exit!");
    return 0;
}

int event_unexpected(void)
{
    printf("Debug.");
    return quit;
}

int (* event[])(void) = { event_idle, event_goingUp, event_goingDown, event_atTop, event_atBottom, event_malfunction, event_unexpected, event_end };
   
int lookup_transitions[][7] = 
{ 
    //                return codes:
    //                up           down         halt       top         bottom         fail          quit
    [_idle]        = {_goingUp,    _goingDown,  _idle,     _unexpected, _unexpected,  _malfunction,  _end},
    [_goingUp]     = {_goingUp,    _unexpected, _idle,     _AtTop,      _AtBottom,    _malfunction,  _end},
    [_goingDown]   = {_unexpected, _goingDown,  _idle,     _AtTop,      _AtBottom,    _malfunction,  _end},
    [_AtTop]       = {_unexpected, _goingDown,  _AtTop,    _unexpected, _unexpected,  _malfunction,  _end},
    [_AtBottom]    = {_goingUp,    _goingDown,  _AtBottom, _unexpected, _unexpected,  _malfunction,  _end},
    [_malfunction] = {_end, _end, _end, _end, _end, _end, _end},
    [_unexpected]  = {_end, _end, _end, _end, _end, _end, _end}
    /* transitions from end state aren't needed */
};

int main()
{
    state_codes_e cur_state = _idle;
    ret_codes_e ret_state;
    int (* event_func)(void);
    printf("Start the elevator!\n");

    for (;;) 
    {
        printf("run FSM \n");
        event_func = event[cur_state]; // 从列表中找到对应状态的执行函数
        ret_state = event_func();             // 函数执行
        if (_end == cur_state)
            break;
        cur_state = lookup_transitions[cur_state][ret_state]; // 查表
    }
    printf("END.");
    return 0;
}


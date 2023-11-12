
#ifndef SOS_INTERFACE_H
#define SOS_INTERFACE_H

#define SOS_MAX_TASKS     20

/*************************************
*             ENUMS                  *
*************************************/
typedef enum 
{
	SOS_STATUS_SUCCEEDED    = 0  ,
	SOS_STATUS_FAILED            ,
	SOS_INVALID_TASK             ,
	SOS_INVALID_ARG              ,
	SOS_NULL_PTR                 
	
}enu_sosErrorState_t;

typedef enum
{
	SOS_UNINITIALIZED     =  0   ,
	SOS_IDLE                     ,
	SOS_RUNNING                  ,
	SOS_STOPPED                  ,
	SOS_READY  
	
}enu_sosState_t;
/*
typedef enum
{   TASK_READY_STATE    =  0    ,
	TASK_WAITING_STATE          ,
    TASK_RUNING_STATE           ,
	TASK_TERMINATED_STATE       ,
	TASK_INVALID_STATE          

}enu_taskState_t;
*/

typdef struct
{
    uint8_t  u8_task_id;
	uint8_t  u8_task_priority;

    uint16_t  u16_task_periodicTime;
    void (*ptrFun_task)(void);
}str_sosTask_t;

typedef struct
{
	uint16_t uint16_tasks ;
	str_sosTask_t str_sosTasks[SOS_MAX_TASKS] ;
}str_sosDatabase_t;



/*************************************
*             Prototypes             *
*************************************/


enu_sosErrorState_t sos_init (void);

enu_sosErrorState_t sos_deinit (void);


enu_sosErrorState_t sos_create_task(str_sosTask_t *ptr_str_sosTask);

enu_sosErrorState_t sos_delete_task (uint8_t u8_a_task_id); 

enu_sosErrorState_t sos_modify_task (str_sosTask_t *ptr_str_sosTask,str_sosTask_t *ptr_str_sosModTask);


enu_sosErrorState_t sos_run(void);

enu_sosErrorState_t sos_disable(void);





#endif /*SOS_INTERFACE_H*/
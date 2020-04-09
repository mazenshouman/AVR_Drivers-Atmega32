/*
 *  File 	   : PushButton_Lcfg.c
 *  Created on : April 8, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

/************************************************************************
 *                              Includes                                *
 ************************************************************************/

#include "Std_types.h"
#include "Dio_Lcfg.h"
#include "Dio.h"
#include "PushButton_Wrapper.h"
#include "PushButton_Cfg.h"
#include "PushButton_Lcfg.h"
#include "PushButton.h"


/************************************************************************
 *      creating instance and initializing configuration structure      *
 ************************************************************************/

PushButton_ConfigType gastr_PushButtonConfigArr[PUSHBUTTON_NUMBER_OF_CONFIGURED_BUTTONS]=
/*            channel ID                           	Active Type          */
{{          DIO_CHANNEL_D5         ,            PUSHBUTTON_ACTIVE_LOW    },
};





/****************************************************************************/

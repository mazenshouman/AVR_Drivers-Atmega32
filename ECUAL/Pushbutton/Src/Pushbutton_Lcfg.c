/*
 *  File 	   : Pushbutton_Lcfg.c
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
#include "Pushbutton_Wrapper.h"
#include "Pushbutton_Cfg.h"
#include "Pushbutton_Lcfg.h"
#include "Pushbutton.h"

/************************************************************************
 *      creating instance and initializing configuration structure      *
 ************************************************************************/

Pushbutton_ConfigType gastr_PushbuttonConfigArr[PUSHBUTTON_NUMBER_OF_CONFIGURED_BUTTONS]=
/*            channel ID                           	Active Type          */
{{          DIO_CHANNEL_D5         ,            PUSHBUTTON_ACTIVE_LOW    },
};




/****************************************************************************/

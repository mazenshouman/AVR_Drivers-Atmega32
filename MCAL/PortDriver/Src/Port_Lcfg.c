/*
 *  File 	   : Port_Lcfg.c
 *  Created on : April 5, 2020
 *  Author	   : Mazen Shouman
 *  Version    : 1.0
 */

/************************************************************************
 *                              Includes                                *
 ************************************************************************/
#include "Std_Types.h"
#include "Port_Cfg.h"
#include "Port_Lcfg.h"



/************************************************************************
 *      creating instance and initializing configuration structure      *
 ************************************************************************/
Port_ConfigType gastr_ConfigArr[NUMBER_OF_CONFIGURED_PINS]=
/*            channel ID                      Direction                          Attachment*/
{{          PORT_CHANNEL_A0         ,       PORT_PIN_OUT                ,           NO_RES  },
 {          PORT_CHANNEL_A1         ,       PORT_PIN_OUT                ,           NO_RES  },
 {          PORT_CHANNEL_A2         ,       PORT_PIN_IN                 ,           PULL_UP_RES	},
 {          PORT_CHANNEL_D5         ,       PORT_PIN_IN                 ,           PULL_UP_RES	}
};







/****************************************************************************/

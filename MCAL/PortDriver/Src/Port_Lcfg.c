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
Port_ConfigType gastr_PortConfigArr[NUMBER_OF_CONFIGURED_PINS]=
/*            channel ID                      Direction                          Attachment*/
{
 {          PORT_CHANNEL_A0         ,       PORT_PIN_OUT                 ,           NO_RES       },
 {          PORT_CHANNEL_A1         ,       PORT_PIN_OUT                 ,           NO_RES       },
 {          PORT_CHANNEL_A2         ,       PORT_PIN_OUT                 ,           NO_RES       },
 {          PORT_CHANNEL_A3         ,       PORT_PIN_OUT                 ,           NO_RES       },
 {          PORT_CHANNEL_A4         ,       PORT_PIN_IN                  ,           PULL_UP_RES  },
 {          PORT_CHANNEL_A5         ,       PORT_PIN_IN                  ,           PULL_UP_RES  },
 {          PORT_CHANNEL_A6         ,       PORT_PIN_IN                  ,           PULL_UP_RES  },
 {          PORT_CHANNEL_A7         ,       PORT_PIN_IN                  ,           PULL_UP_RES  },
 {          PORT_CHANNEL_B0         ,       PORT_PIN_OUT                 ,           NO_RES       },
 {          PORT_CHANNEL_B1         ,       PORT_PIN_OUT                 ,           NO_RES       },
 {          PORT_CHANNEL_C0         ,       PORT_PIN_OUT                 ,           NO_RES       },
 {          PORT_CHANNEL_C1         ,       PORT_PIN_OUT                 ,           NO_RES       },
 {          PORT_CHANNEL_C2         ,       PORT_PIN_OUT                 ,           NO_RES       },
 {          PORT_CHANNEL_C3         ,       PORT_PIN_OUT                 ,           NO_RES       },
 {          PORT_CHANNEL_C4         ,       PORT_PIN_OUT                  ,          NO_RES       },
 {          PORT_CHANNEL_C5         ,       PORT_PIN_OUT                  ,          NO_RES       },
 {          PORT_CHANNEL_C6         ,       PORT_PIN_OUT                  ,          NO_RES       },
 {          PORT_CHANNEL_C7         ,       PORT_PIN_OUT                  ,          NO_RES       },
 {          PORT_CHANNEL_D0         ,       PORT_PIN_OUT                 ,           NO_RES       },
 {          PORT_CHANNEL_D1         ,       PORT_PIN_OUT                 ,           NO_RES       },
 {          PORT_CHANNEL_D2         ,       PORT_PIN_OUT                 ,           NO_RES       },
};







/****************************************************************************/

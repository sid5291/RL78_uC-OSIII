// AGD: New file to include appropriate MCU IOR files

#ifndef IOR5F_H
#define IOR5F_H

#include <platform_cfg.h> // Which RDK are we using? Determines the MCU

#ifdef MCU_RL78G13
	#include <ior5f100LE.h>
	#include <ior5f100LE_ext.h>
#endif

#ifdef MCU_RL78G14
	#include <ior5f104pj.h>
	#include <ior5f104pj_ext.h>
#endif

#endif

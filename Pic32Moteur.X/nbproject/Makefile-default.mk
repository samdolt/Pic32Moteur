#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../lib/PIC32_Cpp/Delay.cpp ../lib/PIC32_Cpp/Key.cpp ../lib/PIC32_Cpp/Port.cpp ../lib/PIC32_Cpp/TextDisplay.cpp ../Mc32Debounce.cpp ../Mc32Delays.cpp ../SK32MX795F512L.cpp ../Main_TP2A_PWM.cpp ../Mc32GestADC.cpp ../Mc32GestionPWM.cpp ../GesFifoTh32.cpp ../Mc32CalCrc16.cpp ../Mc32gest_RS232.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/329993100/Delay.o ${OBJECTDIR}/_ext/329993100/Key.o ${OBJECTDIR}/_ext/329993100/Port.o ${OBJECTDIR}/_ext/329993100/TextDisplay.o ${OBJECTDIR}/_ext/1472/Mc32Debounce.o ${OBJECTDIR}/_ext/1472/Mc32Delays.o ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o ${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o ${OBJECTDIR}/_ext/1472/Mc32GestADC.o ${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o ${OBJECTDIR}/_ext/1472/GesFifoTh32.o ${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o ${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/329993100/Delay.o.d ${OBJECTDIR}/_ext/329993100/Key.o.d ${OBJECTDIR}/_ext/329993100/Port.o.d ${OBJECTDIR}/_ext/329993100/TextDisplay.o.d ${OBJECTDIR}/_ext/1472/Mc32Debounce.o.d ${OBJECTDIR}/_ext/1472/Mc32Delays.o.d ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o.d ${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o.d ${OBJECTDIR}/_ext/1472/Mc32GestADC.o.d ${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o.d ${OBJECTDIR}/_ext/1472/GesFifoTh32.o.d ${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o.d ${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/329993100/Delay.o ${OBJECTDIR}/_ext/329993100/Key.o ${OBJECTDIR}/_ext/329993100/Port.o ${OBJECTDIR}/_ext/329993100/TextDisplay.o ${OBJECTDIR}/_ext/1472/Mc32Debounce.o ${OBJECTDIR}/_ext/1472/Mc32Delays.o ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o ${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o ${OBJECTDIR}/_ext/1472/Mc32GestADC.o ${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o ${OBJECTDIR}/_ext/1472/GesFifoTh32.o ${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o ${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o

# Source Files
SOURCEFILES=../lib/PIC32_Cpp/Delay.cpp ../lib/PIC32_Cpp/Key.cpp ../lib/PIC32_Cpp/Port.cpp ../lib/PIC32_Cpp/TextDisplay.cpp ../Mc32Debounce.cpp ../Mc32Delays.cpp ../SK32MX795F512L.cpp ../Main_TP2A_PWM.cpp ../Mc32GestADC.cpp ../Mc32GestionPWM.cpp ../GesFifoTh32.cpp ../Mc32CalCrc16.cpp ../Mc32gest_RS232.cpp


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/329993100/Delay.o: ../lib/PIC32_Cpp/Delay.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/329993100 
	@${RM} ${OBJECTDIR}/_ext/329993100/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/329993100/Delay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/329993100/Delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/329993100/Delay.o.d" -o ${OBJECTDIR}/_ext/329993100/Delay.o ../lib/PIC32_Cpp/Delay.cpp  
	
${OBJECTDIR}/_ext/329993100/Key.o: ../lib/PIC32_Cpp/Key.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/329993100 
	@${RM} ${OBJECTDIR}/_ext/329993100/Key.o.d 
	@${RM} ${OBJECTDIR}/_ext/329993100/Key.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/329993100/Key.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/329993100/Key.o.d" -o ${OBJECTDIR}/_ext/329993100/Key.o ../lib/PIC32_Cpp/Key.cpp  
	
${OBJECTDIR}/_ext/329993100/Port.o: ../lib/PIC32_Cpp/Port.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/329993100 
	@${RM} ${OBJECTDIR}/_ext/329993100/Port.o.d 
	@${RM} ${OBJECTDIR}/_ext/329993100/Port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/329993100/Port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/329993100/Port.o.d" -o ${OBJECTDIR}/_ext/329993100/Port.o ../lib/PIC32_Cpp/Port.cpp  
	
${OBJECTDIR}/_ext/329993100/TextDisplay.o: ../lib/PIC32_Cpp/TextDisplay.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/329993100 
	@${RM} ${OBJECTDIR}/_ext/329993100/TextDisplay.o.d 
	@${RM} ${OBJECTDIR}/_ext/329993100/TextDisplay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/329993100/TextDisplay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/329993100/TextDisplay.o.d" -o ${OBJECTDIR}/_ext/329993100/TextDisplay.o ../lib/PIC32_Cpp/TextDisplay.cpp  
	
${OBJECTDIR}/_ext/1472/Mc32Debounce.o: ../Mc32Debounce.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32Debounce.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32Debounce.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Mc32Debounce.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/Mc32Debounce.o.d" -o ${OBJECTDIR}/_ext/1472/Mc32Debounce.o ../Mc32Debounce.cpp  
	
${OBJECTDIR}/_ext/1472/Mc32Delays.o: ../Mc32Delays.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32Delays.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32Delays.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Mc32Delays.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/Mc32Delays.o.d" -o ${OBJECTDIR}/_ext/1472/Mc32Delays.o ../Mc32Delays.cpp  
	
${OBJECTDIR}/_ext/1472/SK32MX795F512L.o: ../SK32MX795F512L.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SK32MX795F512L.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/SK32MX795F512L.o.d" -o ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o ../SK32MX795F512L.cpp  
	
${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o: ../Main_TP2A_PWM.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o.d" -o ${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o ../Main_TP2A_PWM.cpp  
	
${OBJECTDIR}/_ext/1472/Mc32GestADC.o: ../Mc32GestADC.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32GestADC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32GestADC.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Mc32GestADC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/Mc32GestADC.o.d" -o ${OBJECTDIR}/_ext/1472/Mc32GestADC.o ../Mc32GestADC.cpp  
	
${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o: ../Mc32GestionPWM.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o.d" -o ${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o ../Mc32GestionPWM.cpp  
	
${OBJECTDIR}/_ext/1472/GesFifoTh32.o: ../GesFifoTh32.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/GesFifoTh32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GesFifoTh32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GesFifoTh32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/GesFifoTh32.o.d" -o ${OBJECTDIR}/_ext/1472/GesFifoTh32.o ../GesFifoTh32.cpp  
	
${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o: ../Mc32CalCrc16.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o.d" -o ${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o ../Mc32CalCrc16.cpp  
	
${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o: ../Mc32gest_RS232.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o.d" -o ${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o ../Mc32gest_RS232.cpp  
	
else
${OBJECTDIR}/_ext/329993100/Delay.o: ../lib/PIC32_Cpp/Delay.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/329993100 
	@${RM} ${OBJECTDIR}/_ext/329993100/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/329993100/Delay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/329993100/Delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/329993100/Delay.o.d" -o ${OBJECTDIR}/_ext/329993100/Delay.o ../lib/PIC32_Cpp/Delay.cpp  
	
${OBJECTDIR}/_ext/329993100/Key.o: ../lib/PIC32_Cpp/Key.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/329993100 
	@${RM} ${OBJECTDIR}/_ext/329993100/Key.o.d 
	@${RM} ${OBJECTDIR}/_ext/329993100/Key.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/329993100/Key.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/329993100/Key.o.d" -o ${OBJECTDIR}/_ext/329993100/Key.o ../lib/PIC32_Cpp/Key.cpp  
	
${OBJECTDIR}/_ext/329993100/Port.o: ../lib/PIC32_Cpp/Port.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/329993100 
	@${RM} ${OBJECTDIR}/_ext/329993100/Port.o.d 
	@${RM} ${OBJECTDIR}/_ext/329993100/Port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/329993100/Port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/329993100/Port.o.d" -o ${OBJECTDIR}/_ext/329993100/Port.o ../lib/PIC32_Cpp/Port.cpp  
	
${OBJECTDIR}/_ext/329993100/TextDisplay.o: ../lib/PIC32_Cpp/TextDisplay.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/329993100 
	@${RM} ${OBJECTDIR}/_ext/329993100/TextDisplay.o.d 
	@${RM} ${OBJECTDIR}/_ext/329993100/TextDisplay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/329993100/TextDisplay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/329993100/TextDisplay.o.d" -o ${OBJECTDIR}/_ext/329993100/TextDisplay.o ../lib/PIC32_Cpp/TextDisplay.cpp  
	
${OBJECTDIR}/_ext/1472/Mc32Debounce.o: ../Mc32Debounce.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32Debounce.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32Debounce.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Mc32Debounce.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/Mc32Debounce.o.d" -o ${OBJECTDIR}/_ext/1472/Mc32Debounce.o ../Mc32Debounce.cpp  
	
${OBJECTDIR}/_ext/1472/Mc32Delays.o: ../Mc32Delays.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32Delays.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32Delays.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Mc32Delays.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/Mc32Delays.o.d" -o ${OBJECTDIR}/_ext/1472/Mc32Delays.o ../Mc32Delays.cpp  
	
${OBJECTDIR}/_ext/1472/SK32MX795F512L.o: ../SK32MX795F512L.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SK32MX795F512L.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/SK32MX795F512L.o.d" -o ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o ../SK32MX795F512L.cpp  
	
${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o: ../Main_TP2A_PWM.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o.d" -o ${OBJECTDIR}/_ext/1472/Main_TP2A_PWM.o ../Main_TP2A_PWM.cpp  
	
${OBJECTDIR}/_ext/1472/Mc32GestADC.o: ../Mc32GestADC.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32GestADC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32GestADC.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Mc32GestADC.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/Mc32GestADC.o.d" -o ${OBJECTDIR}/_ext/1472/Mc32GestADC.o ../Mc32GestADC.cpp  
	
${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o: ../Mc32GestionPWM.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o.d" -o ${OBJECTDIR}/_ext/1472/Mc32GestionPWM.o ../Mc32GestionPWM.cpp  
	
${OBJECTDIR}/_ext/1472/GesFifoTh32.o: ../GesFifoTh32.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/GesFifoTh32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GesFifoTh32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GesFifoTh32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/GesFifoTh32.o.d" -o ${OBJECTDIR}/_ext/1472/GesFifoTh32.o ../GesFifoTh32.cpp  
	
${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o: ../Mc32CalCrc16.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o.d" -o ${OBJECTDIR}/_ext/1472/Mc32CalCrc16.o ../Mc32CalCrc16.cpp  
	
${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o: ../Mc32gest_RS232.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../lib/PIC32_Cpp" -MMD -MF "${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o.d" -o ${OBJECTDIR}/_ext/1472/Mc32gest_RS232.o ../Mc32gest_RS232.cpp  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}           -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,--defsym=_min_heap_size=1024,-Map="TpTestKitPic32.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,-Map="TpTestKitPic32.map"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif

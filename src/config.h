#ifndef config_h
#define config_h

// define class name and unique id
#define MODEL_IDENTIFIER msfmu
 #define GUID "{Altair-MotionView: 19926_PicknPlace2__MKS.fmu: 1645625003.7462988}"

#define CO_SIMULATION
#define MODEL_EXCHANGE

// define model size
#define NX 2
#define NZ 1

#define SET_FLOAT64
#define GET_OUTPUT_DERIVATIVE
#define EVENT_UPDATE

#define FIXED_SOLVER_STEP 1e-3
#define DEFAULT_STOP_TIME 9

#endif /* config_h */

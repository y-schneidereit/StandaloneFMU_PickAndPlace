#ifndef config_h
#define config_h

// define class name and unique id
#define MODEL_IDENTIFIER msfmu
#define GUID "{Altair-MotionView: 19926_PicknPlace2__MKS.fmu: 1645625003.7462988}"
#define RESOURCE_LOCATION ""

//#define FMI2FUNCTIONPREFIX msfmu_
#include "fmi2Functions.h"


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

typedef enum {
    vr_time, vr_x, vr_der_x, vr_k
} ValueReference;

typedef struct {
    double x;
    double der_x;
    double k;
} ModelData;

#endif /* config_h */

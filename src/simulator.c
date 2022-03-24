/* This example demonstrates how to import an FMU implemented as a static library or source code*/

// FMI function prefix (from XML)
#define FMI3_FUNCTION_PREFIX msfmu_
#include "fmi3Functions.h"
#undef FMI3_FUNCTION_PREFIX

#define INSTANTIATION_TOKEN "{Altair-MotionView: 19926_PicknPlace2__MKS.fmu: 1645625003.7462988}"


static void cb_logMessage(fmi3InstanceEnvironment instanceEnvironment, fmi3Status status, fmi3String category, fmi3String message) {
    // log message
}

int main(int argc, char* argv[]) {

    fmi3Instance m = msfmu_fmi3InstantiateModelExchange(
        "instance1",         // instance name
        INSTANTIATION_TOKEN, // instantiation token (from XML)
        NULL,                // resource location
        fmi3False,           // visible
        fmi3False,           // debug logging disabled
        NULL,                // instance environment
        cb_logMessage);      // logger callback

    // simulation ...

   msfmu_fmi3FreeInstance(m);

    return m ? EXIT_SUCCESS : EXIT_FAILURE;
}
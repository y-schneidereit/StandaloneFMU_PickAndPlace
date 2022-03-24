#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define FMI_VERSION 2

#define FMI2_FUNCTION_PREFIX s1_
#include "fmi2Functions.h"
#undef FMI2_FUNCTION_PREFIX

#include "util.h"

// callback functions
static void cb_logMessage(fmi2ComponentEnvironment componentEnvironment, fmi2String instanceName, fmi2Status status, fmi2String category, fmi2String message, ...) {
    printf("%s\n", message);
}

static void* cb_allocateMemory(size_t nobj, size_t size) {
    return calloc(nobj, size);
}

static void cb_freeMemory(void* obj) {
    free(obj);
}

int main(int argc, char* argv[]) {

    fmi2Real startTime, stopTime, h, tc;
    fmi2Status status = fmi2OK;

    const char *guid = "{Altair-MotionView: 19926_PicknPlace2__MKS.fmu: 1645625003.7462988}";

    printf("Running CoSimulation example... ");
    fmi2CallbackFunctions callbacks = { cb_logMessage, cb_allocateMemory, cb_freeMemory, NULL, NULL };
// instantiate both FMUs
    fmi2Component s1 = s1_fmi2Instantiate("instance1", fmi2CoSimulation, guid, "", &callbacks, fmi2False, fmi2False);

    /*

if (s1 == NULL)
    return EXIT_FAILURE;

// start and stop time
startTime = 0;
stopTime = 10;

// communication step size
h = 0.01;

// set all variable start values (of "ScalarVariable / <type> / start")
// s1_fmi3SetReal/Integer/Boolean/String(s1, ...);
// s2_fmi3SetReal/Integer/Boolean/String(s2, ...);

// initialize the FMUs
s1_fmi3EnterInitializationMode(s1, fmi3False, 0.0, startTime, fmi3True, stopTime);
s2_fmi3EnterInitializationMode(s2, fmi3False, 0.0, startTime, fmi3True, stopTime);

// set the input values at time = startTime
// fmi3SetReal/Integer/Boolean/String(s1, ...);
// fmi3SetReal/Integer/Boolean/String(s2, ...);

s1_fmi3ExitInitializationMode(s1);
s2_fmi3ExitInitializationMode(s2);

////////////////////////
// Simulation sub-phase
tc = startTime; // current time

while ((tc < stopTime) && (status == fmi3OK)) {

    // retrieve outputs
    // fmi3GetReal(s1, ..., 1, &y1);
    // fmi3GetReal(s2, ..., 1, &y2);

    // set inputs
    // fmi3SetReal(s1, ..., 1, &y2);
    // fmi3SetReal(s2, ..., 1, &y1);

    // call instance s1 and check status
    fmi3Boolean eventEncountered, terminateSimulation, earlyReturn;
    fmi3Float64 lastSuccessfulTime;

    status = s1_fmi3DoStep(s1, tc, h, fmi3True, &eventEncountered, &terminateSimulation, &earlyReturn, &lastSuccessfulTime);

    if (terminateSimulation) {
        printf("Instance s1 requested to terminate simulation.");
        break;
    }

    // call instance s2 and check status as above
    status = s2_fmi3DoStep(s2, tc, h, fmi3True, &eventEncountered, &terminateSimulation, &earlyReturn, &lastSuccessfulTime);

    // ...

    // increment current time
    tc += h;
 }
 
//////////////////////////
// Shutdown sub-phase
if (status != fmi3Error && status != fmi3Fatal) {
    s1_fmi3Terminate(s1);
    s2_fmi3Terminate(s2);
}

if (status != fmi3Fatal) {
    s1_fmi3FreeInstance(s1);
    s2_fmi3FreeInstance(s2);
}
// end::CoSimulation[]
*/
    printf("done.\n");

    return EXIT_SUCCESS;
}

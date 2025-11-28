#pragma once

#define RunBeforeMain(Function) \
    class Function##BeforeMain {    \
        public: \
        Function##BeforeMain() \
        { \
            Function();\
        }\
    }; \
    static Function##BeforeMain Function##PreMainInstance;
#include "State.h"
#include "src/Programs/WordClockProgram.h"

State::State(){
    ActiveProgram = new WordClockProgram();
}


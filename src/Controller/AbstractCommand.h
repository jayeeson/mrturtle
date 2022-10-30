#pragma once

class AbstractCommand
{
   public:
    virtual void Execute() = 0;
    // return true if this command takes 0 time
    // ie backend only
    virtual bool InstaExecution() { return true; }
};
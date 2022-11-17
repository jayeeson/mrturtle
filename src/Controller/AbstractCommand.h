#pragma once

class AbstractCommand
{
   public:
    virtual bool Execute() = 0;
    // return true if this command takes 0 time
    // ie backend only
    virtual bool InstaExecution() { return true; }
};
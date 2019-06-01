#include <string>
#include "Process.h"
void Process::setPid(int pid){
    this->pid = pid;
}
string Process::getPid()const {
    return this->pid;
}
string Process::getProcess(){
    if(!ProcessParser::isPidExisting(this->pid))
        return "";
    this->mem = ProcessParser::getVmSize(this->pid);
    this->upTime = ProcessParser::getProcUpTime(this->pid);
    this->cpu = ProcessParser::getCpuPercent(this->pid);

    return (this->pid + "   " //TODO: finish the string! this->user + "   "+ mem...cpu...upTime...;
                    + this->user
                    + "  "
                    + this->mem.substr(0, 5)
                    + "  "
                    + this->cpu.substr(0, 5)
                    + "  "
                    + this->upTime.substr(0, 5)
                    + "  "
                    + this->cmd.substr(0, 5)
                    + "...");
}

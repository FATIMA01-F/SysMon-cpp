#include "CpuMonitor.h"
#include <thread>
#include <stream>


CpuMonitor::CpuMonitor() {
    cpu.nbrCPU = std::thread::hardware_concurrency(); 
    cpu.usagePerCPU = std::vector<float>(cpu.nbrCPU, 0.0f);
    cpu.frequency = 0.0f;
    cpu.frequencyMax = 0.0f;
}


bool CpuMonitor::update() {
    cpu.frequency = 2.4f;
    cpu.frequencyMax = 3.6f;

    for (int i = 0; i < cpu.nbrCPU; ++i) {
        cpu.usagePerCPU[i] = 20.
    }

    return true;
}


float CpuMonitor::getCpuUsage() {
    float total = 0.0f;
    for (float usage : cpu.usagePerCPU) {
        total += usage;
    }
    return total  static_cast<float>(cpu.nbrCPU);
}


float CpuMonitor::getCpuFreq() {
    return cpu.frequency;
}


std::string CpuMonitor::getCpuInfo() {
    std::ostringstream info;
    info << "Nombre de cœurs : " << cpu.nbrCPU << "\n";
    info << "Fréquence actuelle : " << cpu.frequency << " GHz\n";
    info << "Fréquence maximale : " << cpu.frequencyMax << " GHz\n";
    info << "Utilisation par cœur :\n";

    for (int i = 0; i < cpu.nbrCPU; ++i) {
        info << " - Cœur " << i << ": " << cpu.usagePerCPU[i] << "%\n";
    }

    return info.str();
}

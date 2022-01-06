#include <mod/amlmod.h>

MYMOD(peepo.uvanim, GTA:SA UVAnim Fix, 1.0, Peepo)
NEEDGAME(com.rockstargames.gtasa)

extern "C" void OnModLoad()
{
    uintptr_t pAddr = aml->GetLib("libGTASA.so") + 0x6BD1E4;
    if(pAddr != 0x6BD1E4)
    {
        aml->Unprot(pAddr, sizeof(bool));
        *(bool*)pAddr = true;
    }
}
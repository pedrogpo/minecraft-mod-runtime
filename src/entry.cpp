#include "includes.hpp"
#include "mod/mod.hpp"

void initialize();

//workarround
HMODULE hmodule;

bool __stdcall DllMain( HMODULE h_module,
                       DWORD  reason,
                       LPVOID lp_reserved
                     )
{
    if (reason != DLL_PROCESS_ATTACH) return false;

    //workarround
    hmodule = h_module;

    // reduce the size of the dll by removing dlll_thread_*
    LI_FN(DisableThreadLibraryCalls).safe_cached()(h_module);

    // initialize the main thread
    LI_FN(CreateThread).safe_cached()(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(initialize), nullptr, 0, nullptr);

    return true;
}

void initialize() {
#ifdef _DEBUG
      // Attach a console for debugging.
    utils::console::attach_console();
#endif

    // Initialize the mod.
    mod::g_instance->initialize();
    
    // Initialize the mod.
    mod::g_instance->shutdown();

#ifdef _DEBUG
    // Free the console when debugging is done.
    utils::console::free_console();
#endif

    // Free the DLL.
    FreeLibraryAndExitThread(hmodule, 0);
}
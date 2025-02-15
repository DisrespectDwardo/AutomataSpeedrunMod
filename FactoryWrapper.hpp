#pragma once

#include <d2d1_2.h>
#include <dwrite.h>
#include <dxgi1_2.h>
#include <atlbase.h>
#include "SwapChainWrapper.hpp"

namespace DxWrappers {

class DXGIFactoryWrapper : public IDXGIFactory2 {
    ULONG m_refCount;
    CComPtr<IDXGIFactory2> m_target;
    CComPtr<ID2D1Factory2> m_D2DFactory;
    CComPtr<DXGISwapChainWrapper> m_currentSwapChain;

public:
    DXGIFactoryWrapper(CComPtr<IDXGIFactory2> target);
    virtual ~DXGIFactoryWrapper();
    void toggleDvdMode(bool enabled);

    virtual HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject) override;
    virtual ULONG __stdcall AddRef() override;
    virtual ULONG __stdcall Release() override;
    virtual HRESULT __stdcall SetPrivateData(REFGUID Name, UINT DataSize, const void* pData) override;
    virtual HRESULT __stdcall SetPrivateDataInterface(REFGUID Name, const IUnknown* pUnknown) override;
    virtual HRESULT __stdcall GetPrivateData(REFGUID Name, UINT* pDataSize, void* pData) override;
    virtual HRESULT __stdcall GetParent(REFIID riid, void** ppParent) override;
    virtual HRESULT __stdcall EnumAdapters(UINT Adapter, IDXGIAdapter** ppAdapter) override;
    virtual HRESULT __stdcall MakeWindowAssociation(HWND WindowHandle, UINT Flags) override;
    virtual HRESULT __stdcall GetWindowAssociation(HWND* pWindowHandle) override;
    virtual HRESULT __stdcall CreateSwapChain(IUnknown* pDevice, DXGI_SWAP_CHAIN_DESC* pDesc, IDXGISwapChain** ppSwapChain) override;
    virtual HRESULT __stdcall CreateSoftwareAdapter(HMODULE Module, IDXGIAdapter** ppAdapter) override;
    virtual HRESULT __stdcall EnumAdapters1(UINT Adapter, IDXGIAdapter1** ppAdapter) override;
    virtual BOOL __stdcall IsCurrent() override;
    virtual BOOL __stdcall IsWindowedStereoEnabled() override;
    virtual HRESULT __stdcall CreateSwapChainForHwnd(IUnknown* pDevice, HWND hWnd, const DXGI_SWAP_CHAIN_DESC1* pDesc, const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc, IDXGIOutput* pRestrictToOutput, IDXGISwapChain1** ppSwapChain) override;
    virtual HRESULT __stdcall CreateSwapChainForCoreWindow(IUnknown* pDevice, IUnknown* pWindow, const DXGI_SWAP_CHAIN_DESC1* pDesc, IDXGIOutput* pRestrictToOutput, IDXGISwapChain1** ppSwapChain) override;
    virtual HRESULT __stdcall GetSharedResourceAdapterLuid(HANDLE hResource, LUID* pLuid) override;
    virtual HRESULT __stdcall RegisterStereoStatusWindow(HWND WindowHandle, UINT wMsg, DWORD* pdwCookie) override;
    virtual HRESULT __stdcall RegisterStereoStatusEvent(HANDLE hEvent, DWORD* pdwCookie) override;
    virtual void __stdcall UnregisterStereoStatus(DWORD dwCookie) override;
    virtual HRESULT __stdcall RegisterOcclusionStatusWindow(HWND WindowHandle, UINT wMsg, DWORD* pdwCookie) override;
    virtual HRESULT __stdcall RegisterOcclusionStatusEvent(HANDLE hEvent, DWORD* pdwCookie) override;
    virtual void __stdcall UnregisterOcclusionStatus(DWORD dwCookie) override;
    virtual HRESULT __stdcall CreateSwapChainForComposition(IUnknown* pDevice, const DXGI_SWAP_CHAIN_DESC1* pDesc, IDXGIOutput* pRestrictToOutput, IDXGISwapChain1** ppSwapChain) override;

};

} // namespace DxWrappers
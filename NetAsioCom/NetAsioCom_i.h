

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Tue Jun 03 13:45:40 2014
 */
/* Compiler settings for .\NetAsioCom.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __NetAsioCom_i_h__
#define __NetAsioCom_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISocketClient_FWD_DEFINED__
#define __ISocketClient_FWD_DEFINED__
typedef interface ISocketClient ISocketClient;
#endif 	/* __ISocketClient_FWD_DEFINED__ */


#ifndef __SocketClient_FWD_DEFINED__
#define __SocketClient_FWD_DEFINED__

#ifdef __cplusplus
typedef class SocketClient SocketClient;
#else
typedef struct SocketClient SocketClient;
#endif /* __cplusplus */

#endif 	/* __SocketClient_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISocketClient_INTERFACE_DEFINED__
#define __ISocketClient_INTERFACE_DEFINED__

/* interface ISocketClient */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISocketClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11AE7208-FFF5-45B4-8BC4-4B9B6981E3C3")
    ISocketClient : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendPacket( 
            /* [in] */ BSTR bstrIP,
            /* [in] */ BSTR bstrPort,
            /* [in] */ long lTimeoutSecond,
            /* [in] */ BSTR bstrMessage,
            /* [out] */ VARIANT *varRetMessage,
            /* [retval][out] */ VARIANT *pReturn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISocketClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISocketClient * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISocketClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISocketClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISocketClient * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISocketClient * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISocketClient * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISocketClient * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendPacket )( 
            ISocketClient * This,
            /* [in] */ BSTR bstrIP,
            /* [in] */ BSTR bstrPort,
            /* [in] */ long lTimeoutSecond,
            /* [in] */ BSTR bstrMessage,
            /* [out] */ VARIANT *varRetMessage,
            /* [retval][out] */ VARIANT *pReturn);
        
        END_INTERFACE
    } ISocketClientVtbl;

    interface ISocketClient
    {
        CONST_VTBL struct ISocketClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISocketClient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISocketClient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISocketClient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISocketClient_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISocketClient_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISocketClient_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISocketClient_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISocketClient_SendPacket(This,bstrIP,bstrPort,lTimeoutSecond,bstrMessage,varRetMessage,pReturn)	\
    ( (This)->lpVtbl -> SendPacket(This,bstrIP,bstrPort,lTimeoutSecond,bstrMessage,varRetMessage,pReturn) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISocketClient_INTERFACE_DEFINED__ */



#ifndef __NetAsioComLib_LIBRARY_DEFINED__
#define __NetAsioComLib_LIBRARY_DEFINED__

/* library NetAsioComLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_NetAsioComLib;

EXTERN_C const CLSID CLSID_SocketClient;

#ifdef __cplusplus

class DECLSPEC_UUID("12467F5C-0E93-425C-8377-F4F30306A0C3")
SocketClient;
#endif
#endif /* __NetAsioComLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



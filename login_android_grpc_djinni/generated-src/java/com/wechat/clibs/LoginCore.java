// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from demo.djinni

package com.wechat.clibs;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class LoginCore {
    public abstract void userLogin(String account, String password);

    public abstract void userSign(String account, String password);

    public abstract void userLogout();

    public abstract void checkLoginStatus();

    public abstract void checkConnection();

    public static LoginCore create(LoginListener listener)
    {
        return CppProxy.create(listener);
    }

    private static final class CppProxy extends LoginCore
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void _djinni_private_destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            _djinni_private_destroy();
            super.finalize();
        }

        @Override
        public void userLogin(String account, String password)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_userLogin(this.nativeRef, account, password);
        }
        private native void native_userLogin(long _nativeRef, String account, String password);

        @Override
        public void userSign(String account, String password)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_userSign(this.nativeRef, account, password);
        }
        private native void native_userSign(long _nativeRef, String account, String password);

        @Override
        public void userLogout()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_userLogout(this.nativeRef);
        }
        private native void native_userLogout(long _nativeRef);

        @Override
        public void checkLoginStatus()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_checkLoginStatus(this.nativeRef);
        }
        private native void native_checkLoginStatus(long _nativeRef);

        @Override
        public void checkConnection()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_checkConnection(this.nativeRef);
        }
        private native void native_checkConnection(long _nativeRef);

        public static native LoginCore create(LoginListener listener);
    }
}

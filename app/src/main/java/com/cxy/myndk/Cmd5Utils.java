package com.cxy.myndk;

/**
 * Created by msi on 2018/1/16.
 */

public class Cmd5Utils {
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI(String str);

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("CMD5-lib");
    }
}

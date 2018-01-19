package com.cxy.myndk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    // Example of a call to a native method
    TextView tv = (TextView) findViewById(R.id.sample_text);
        Cmd5Utils utils = new Cmd5Utils();
    String md5 = utils.stringFromJNI("client=doctor&noncestr=e704c2d8-405c-4370-b67c-72d322061d4a&passWord=123456&timestamp=1516070115383&userName=13522226666&version=2.8.1&");
        Log.d("chen", "onCreate: "+md5);
    tv.setText(md5);
    }


}

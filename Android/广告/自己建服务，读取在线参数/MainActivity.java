package com.example.spanking;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

import android.app.Activity;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.view.WindowManager;
import android.widget.ImageButton;

import com.wfun.WFun;

public class MainActivity extends Activity {
	private ImageButton startGame;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        startGame = (ImageButton)findViewById(R.id.start_game);
        startGame.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				new GetOnlineStateThread().start();	//启动线程	
			}
		});
    }
    
    private class GetOnlineStateThread extends Thread{
    	@Override
    	public void run() {
    		HttpClient httpClient = new DefaultHttpClient();
    		//访问number为1的参数
			HttpGet httpGet = new HttpGet("http://192.168.3.106:8080/SwitchOnline/SwitchOnlineServlet?number=1");
			try {
				HttpResponse httpResponse = httpClient.execute(httpGet);
				InputStream is = httpResponse.getEntity().getContent();
				
				BufferedReader reader = new BufferedReader(new InputStreamReader(is));
				StringBuilder sb = new StringBuilder();
				String line = "";
				while(null != (line = reader.readLine())){
					sb.append(line);
				}
				System.out.println(sb.toString());
			} catch (Exception e) {
				e.printStackTrace();
			}
    	}
    }
}

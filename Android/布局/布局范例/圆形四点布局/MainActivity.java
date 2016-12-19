package com.tiantian.test;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.view.animation.AnimationSet;
import android.view.animation.RotateAnimation;
import android.widget.ImageButton;
import android.widget.RadioButton;
import android.widget.RelativeLayout;

public class MainActivity extends Activity {
	private CircleView circleView;
	private int width;
	private int height;
	private RadioButton imageA;
	private RadioButton imageB;
	private RadioButton imageC;
	private RadioButton imageD;
	private ViewGroup viewGroup;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        width = getWindowManager().getDefaultDisplay().getWidth();
        height = getWindowManager().getDefaultDisplay().getHeight();
        viewGroup = (ViewGroup) findViewById(R.id.viewGroup);
        circleView = new CircleView(this, width, height);
        viewGroup.addView(circleView, 1, new RelativeLayout.LayoutParams(RelativeLayout.LayoutParams.FILL_PARENT, RelativeLayout.LayoutParams.FILL_PARENT));
        imageA = (RadioButton) findViewById(R.id.imageA);
        imageB = (RadioButton) findViewById(R.id.imageB);
        imageC = (RadioButton) findViewById(R.id.imageC);
        imageD = (RadioButton) findViewById(R.id.imageD);
        imageA.setOnClickListener(new ButtonListener());
        imageB.setOnClickListener(new ButtonListener());
        imageC.setOnClickListener(new ButtonListener());
        imageD.setOnClickListener(new ButtonListener());
        setPosition();
    }
    
    private void setPosition() {
    	RelativeLayout.LayoutParams params = (RelativeLayout.LayoutParams) imageA.getLayoutParams();
    	params.setMargins(circleView.getTopCirclePoint().x - 24, circleView.getTopCirclePoint().y - 24, 0, 0);
    	params = (RelativeLayout.LayoutParams) imageB.getLayoutParams();
    	params.setMargins(circleView.getBottomCirclePoint().x - 24, circleView.getBottomCirclePoint().y - 24, 0, 0);
    	params = (RelativeLayout.LayoutParams) imageC.getLayoutParams();
    	params.setMargins(circleView.getLeftCirclePoint().x - 24, circleView.getLeftCirclePoint().y - 24, 0, 0);
    	params = (RelativeLayout.LayoutParams) imageD.getLayoutParams();
    	params.setMargins(circleView.getRightCirclePoint().x - 24, circleView.getRightCirclePoint().y - 24, 0, 0);
	}
    
    private class ButtonListener implements OnClickListener{

		@Override
		public void onClick(View v) {
			switch(v.getId()){
			case R.id.imageA:
				System.out.println("imageA is clicked");
				break;
			case R.id.imageB:
				System.out.println("imageB is clicked");
				break;
			case R.id.imageC:
				System.out.println("imageC is clicked");
				break;
			case R.id.imageD:
				System.out.println("imageD is clicked");
				break;
			}
			
		}
    	
    }
    
    
}
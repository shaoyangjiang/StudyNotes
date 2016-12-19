package com.tiantian.test;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Paint.Style;
import android.graphics.Point;
import android.util.AttributeSet;
import android.view.View;

public class CircleView extends View{
	private Context context;
	private int circleX;
	private int circleY;
	private int radius;
	private Paint paint;
	
	public CircleView(Context context, int width, int height) {
		super(context);
		this.context = context;
		circleX = width / 2;
    	circleY = (int) ((height / 2) * 0.9);
    	radius = (int) ((width / 2) * 0.7);
		paint = new Paint();
	}
	public CircleView(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
	}
	public CircleView(Context context, AttributeSet attrs) {
		super(context, attrs);
	}

	@Override
	protected void onDraw(Canvas canvas) {
		paint = new Paint();
    	paint.setColor(Color.GRAY);
    	paint.setStyle(Style.STROKE);
    	paint.setStrokeWidth(5);
    	paint.setAntiAlias(true);
//    	canvas.drawCircle(160, 200, 110, paint);
    	canvas.drawCircle(circleX, circleY, radius, paint);
	}
	/**
	 * 取得圆最上方的点
	 * @return 返回最上方的点Point对象
	 */
	public Point getTopCirclePoint(){
//		return new Point(160, 200 - 110);
		return new Point(circleX, circleY - radius);
	}
	/**
	 * 取得圆最下方的点
	 * @return 返回最下方的点Point对象
	 */
	public Point getBottomCirclePoint(){
//		return new Point(160, 200 + 110);
		return new Point(circleX, circleY + radius);
	}
	/**
	 * 取得圆最左边的点
	 * @return 返回最左边的点Point对象
	 */
	public Point getLeftCirclePoint(){
//		return new Point(160 - 110, 200);
		return new Point(circleX - radius, circleY);
	}
	/**
	 * 取得圆最右边的点
	 * @return 返回最右边的点Point对象
	 */
	public Point getRightCirclePoint(){
//		return new Point(160 + 110, 200);
		return new Point(circleX + radius, circleY);
	}

}






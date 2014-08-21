package com.giant.jni;

public class JniBrige {

	public native void showExit();
	
	private static JniBrige _instance;
	
	public static Object getObject(){
		return getInstance();
	}
	
	
	public static JniBrige getInstance(){
		if(_instance==null){
			_instance = new JniBrige();
		}
		return _instance;
	}
	
}

package com.bgstation0.android.sample.fragmenttransaction_;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`
	FragmentManager fragmentManager = null;	// FragmentManager�I�u�W�F�N�gfragmentManager��null�ɏ�����.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // FragmentManager�̎擾.
        fragmentManager = getFragmentManager();	// getFragmentManager��fragmentManager���擾.
        
    }
    
    // ���j���[���쐬���ꂽ��.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
    	
    	// ���j���[�̍쐬
    	getMenuInflater().inflate(R.menu.main, menu);	// getMenuInflater��MenuItem���擾��, ���̂܂�inflate�Ŏw�肳�ꂽR.menu.main������menu���쐬.
    	return true;	// true��Ԃ�.
    	
    }
    
    // ���j���[���I�����ꂽ��.
    @Override
    public boolean onOptionsItemSelected(MenuItem item){
    
    	// �ǂ̃��j���[���I�����ꂽ��.
    	switch (item.getItemId()){	// �A�C�e��ID���ƂɐU�蕪��.
    	
    		// Menu1
    		case R.id.menu_menu1:
    			
    			// Menu1�u���b�N
    			{
    				
    				// �t���O�����g"tag1"�����邩�m�F����.
    				Fragment f1 = fragmentManager.findFragmentByTag("tag1");	// fragmentManager.findFragmentByTag��"tag1"��Fragment��T��, �����f1�Ɋi�[.
    				if (f1 == null){	// f1��null�Ȃ�.
        				// �t���O�����g�̒ǉ�
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransaction��fragmentTransaction���擾.
    					Fragment fragment = new MainFragment();	// MainFragment�I�u�W�F�N�g���쐬��, Fragment�^��fragment�Ɋi�[.
    					Bundle args = new Bundle();	// �u������Fragment�ɓn���p�����[�^args��Bundle�I�u�W�F�N�g�Ƃ��č쐬.
    					args.putString("text", "fragment1");	// �L�[��"text", �l��"fragment1".
    					args.putString("color", "red");	// �L�[��"color", �l��"red".
    					fragment.setArguments(args);	// fragment.setArguments��args���Z�b�g.
    					fragmentTransaction.add(R.id.framelayout1, fragment, "tag1");	// fragmentTransaction.add��R.id.framelayout1��fragment��ǉ�.("tag1"���^�O�t��.)
    					//fragmentTransaction.replace(R.id.framelayout1, fragment, "tag1");	// fragmentTransaction.replace��R.id.framelayout1��fragment�ɒu��.("tag1"���^�O�t��.)
    					fragmentTransaction.addToBackStack(null);	// fragmentTransaction.addToBackStack�Œu���O�̏�Ԃ��o�b�N�X�^�b�N�ɕۑ�.
    					fragmentTransaction.commit();	// fragmentTransaction.commit�Ŋm��.
    				}
    				else{	// f1��null�łȂ��ꍇ.(f1�����������ꍇ.)
    					// �t���O�����g�̕\��
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransaction��fragmentTransaction���擾.
    					fragmentTransaction.show(f1);	// fragmentTransaction.show��f1��\��.
    					fragmentTransaction.commit();	// fragmentTransaction.commit�Ŋm��.
    				}
    				
    				// �t���O�����g"tag2"������ΉB��.
    				Fragment f2 = fragmentManager.findFragmentByTag("tag2");	// fragmentManager.findFragmentByTag��"tag2"��Fragment��T��, �����f2�Ɋi�[.
    				if (f2 != null){	// f2��null�łȂ����.
    					// �t���O�����g�̔�\��
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransaction��fragmentTransaction���擾.
    					fragmentTransaction.hide(f2);	// fragmentTransaction.hide��f2���\��.
    					fragmentTransaction.commit();	// fragmentTransaction.commit�Ŋm��.
    				}
    				
    				// �t���O�����g"tag3"������ΉB��.
    				Fragment f3 = fragmentManager.findFragmentByTag("tag3");	// fragmentManager.findFragmentByTag��"tag3"��Fragment��T��, �����f3�Ɋi�[.
    				if (f3 != null){	// f3��null�łȂ����.
    					// �t���O�����g�̔�\��
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransaction��fragmentTransaction���擾.
    					fragmentTransaction.hide(f3);	// fragmentTransaction.hide��f3���\��.
    					fragmentTransaction.commit();	// fragmentTransaction.commit�Ŋm��.
    				}
    				
    			}
    			
    			break;
    			
    		// Menu2
    		case R.id.menu_menu2:
    			
    			//�@Menu2�u���b�N
    			{

    				// �t���O�����g"tag2"�����邩�m�F����.
    				Fragment f2 = fragmentManager.findFragmentByTag("tag2");	// fragmentManager.findFragmentByTag��"tag2"��Fragment��T��, �����f2�Ɋi�[.
    				if (f2 == null){	// f2��null�Ȃ�.
        				// �t���O�����g�̒ǉ�
	    				FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransaction��fragmentTransaction���擾.
	    				Fragment fragment = new MainFragment();	// MainFragment�I�u�W�F�N�g���쐬��, Fragment�^��fragment�Ɋi�[.
	    				Bundle args = new Bundle();	// �u������Fragment�ɓn���p�����[�^args��Bundle�I�u�W�F�N�g�Ƃ��č쐬.
	    				args.putString("text", "fragment2");	// �L�[��"text", �l��"fragment2".
	    				args.putString("color", "green");	// �L�[��"color", �l��"green".
	    				fragment.setArguments(args);	// fragment.setArguments��args���Z�b�g.
	    				fragmentTransaction.add(R.id.framelayout1, fragment, "tag2");	// fragmentTransaction.add��R.id.framelayout1��fragment��ǉ�.("tag2"���^�O�t��.)
	    				//fragmentTransaction.replace(R.id.framelayout1, fragment, "tag2");	// fragmentTransaction.replace��R.id.framelayout1��fragment�ɒu��.("tag2"���^�O�t��.)
	    				fragmentTransaction.addToBackStack(null);	// fragmentTransaction.addToBackStack�Œu���O�̏�Ԃ��o�b�N�X�^�b�N�ɕۑ�.
	    				fragmentTransaction.commit();	// fragmentTransaction.commit�Ŋm��.
    				}
    				else{	// f2��null�łȂ��ꍇ.(f1�����������ꍇ.)
    					// �t���O�����g�̕\��
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransaction��fragmentTransaction���擾.
    					fragmentTransaction.show(f2);	// fragmentTransaction.show��f2��\��.
    					fragmentTransaction.commit();	// fragmentTransaction.commit�Ŋm��.
    				}
    				
    				// �t���O�����g"tag1"������ΉB��.
    				Fragment f1 = fragmentManager.findFragmentByTag("tag1");	// fragmentManager.findFragmentByTag��"tag1"��Fragment��T��, �����f1�Ɋi�[.
    				if (f1 != null){	// f1��null�łȂ����.
    					// �t���O�����g�̔�\��
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransaction��fragmentTransaction���擾.
    					fragmentTransaction.hide(f1);	// fragmentTransaction.hide��f1���\��.
    					fragmentTransaction.commit();	// fragmentTransaction.commit�Ŋm��.
    				}
    				
    				// �t���O�����g"tag3"������ΉB��.
    				Fragment f3 = fragmentManager.findFragmentByTag("tag3");	// fragmentManager.findFragmentByTag��"tag3"��Fragment��T��, �����f3�Ɋi�[.
    				if (f3 != null){	// f3��null�łȂ����.
    					// �t���O�����g�̔�\��
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransaction��fragmentTransaction���擾.
    					fragmentTransaction.hide(f3);	// fragmentTransaction.hide��f3���\��.
    					fragmentTransaction.commit();	// fragmentTransaction.commit�Ŋm��.
    				}
    				
    			}
    					
    			break;
    	
    		// Menu3
    		case R.id.menu_menu3:
    			
    			// Menu3�u���b�N
    			{

    				// �t���O�����g"tag3"�����邩�m�F����.
    				Fragment f3 = fragmentManager.findFragmentByTag("tag3");	// fragmentManager.findFragmentByTag��"tag3"��Fragment��T��, �����f3�Ɋi�[.
    				if (f3 == null){	// f3��null�Ȃ�.
        				// �t���O�����g�̒ǉ�
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransaction��fragmentTransaction���擾.
    					Fragment fragment = new MainFragment();	// MainFragment�I�u�W�F�N�g���쐬��, Fragment�^��fragment�Ɋi�[.
    					Bundle args = new Bundle();	// �u������Fragment�ɓn���p�����[�^args��Bundle�I�u�W�F�N�g�Ƃ��č쐬.
    					args.putString("text", "fragment3");	// �L�[��"text", �l��"fragment3".
    					args.putString("color", "blue");	// �L�[��"color", �l��"blue".
    					fragment.setArguments(args);	// fragment.setArguments��args���Z�b�g.
    					fragmentTransaction.add(R.id.framelayout1, fragment, "tag3");	// fragmentTransaction.add��R.id.framelayout1��fragment��ǉ�.("tag3"���^�O�t��.)
    					//fragmentTransaction.replace(R.id.framelayout1, fragment, "tag3");	// fragmentTransaction.replace��R.id.framelayout1��fragment�ɒu��.("tag3"���^�O�t��.)
    					fragmentTransaction.addToBackStack(null);	// fragmentTransaction.addToBackStack�Œu���O�̏�Ԃ��o�b�N�X�^�b�N�ɕۑ�.
    					fragmentTransaction.commit();	// fragmentTransaction.commit�Ŋm��.
    				}
    				else{	// f3��null�łȂ��ꍇ.(f3�����������ꍇ.)
    					// �t���O�����g�̕\��
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransaction��fragmentTransaction���擾.
    					fragmentTransaction.show(f3);	// fragmentTransaction.show��f3��\��.
    					fragmentTransaction.commit();	// fragmentTransaction.commit�Ŋm��.
    				}
    				
    				// �t���O�����g"tag1"������ΉB��.
    				Fragment f1 = fragmentManager.findFragmentByTag("tag1");	// fragmentManager.findFragmentByTag��"tag1"��Fragment��T��, �����f1�Ɋi�[.
    				if (f1 != null){	// f1��null�łȂ����.
    					// �t���O�����g�̔�\��
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransaction��fragmentTransaction���擾.
    					fragmentTransaction.hide(f1);	// fragmentTransaction.hide��f1���\��.
    					fragmentTransaction.commit();	// fragmentTransaction.commit�Ŋm��.
    				}
    				
    				// �t���O�����g"tag2"������ΉB��.
    				Fragment f2 = fragmentManager.findFragmentByTag("tag2");	// fragmentManager.findFragmentByTag��"tag2"��Fragment��T��, �����f2�Ɋi�[.
    				if (f2 != null){	// f2��null�łȂ����.
    					// �t���O�����g�̔�\��
    					FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();	// fragmentManager.beginTransaction��fragmentTransaction���擾.
    					fragmentTransaction.hide(f2);	// fragmentTransaction.hide��f2���\��.
    					fragmentTransaction.commit();	// fragmentTransaction.commit�Ŋm��.
    				}
    				
    			}
    			
    			break;
    			
    	}
    	
    	return super.onOptionsItemSelected(item);	// �e�N���X���菈��
    	
    }
    
}
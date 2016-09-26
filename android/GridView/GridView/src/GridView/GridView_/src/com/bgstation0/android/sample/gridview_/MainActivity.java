package com.bgstation0.android.sample.gridview_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.GridView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // GridItem�z��Œǉ�����v�f���`.
        GridItem[] griditems = new GridItem[8];	// GridItem�z��griditems(�v�f��8)
        for (int i = 0; i < 8; i++){	// �v�f���̕��J��Ԃ�.
        	griditems[i] = new GridItem();	// GridItem�I�u�W�F�N�g�C���X�^���X�𐶐���, �e�v�f�Ɋi�[.
        }
        griditems[0].name = "one";
        griditems[0].colorno = 0;
        griditems[1].name = "two";
        griditems[1].colorno = 1;
        griditems[2].name = "three";
        griditems[2].colorno = 0;
        griditems[3].name = "four";
        griditems[3].colorno = 1;
        griditems[4].name = "five";
        griditems[4].colorno = 1;
        griditems[5].name = "six";
        griditems[5].colorno = 0;
        griditems[6].name = "seven";
        griditems[6].colorno = 1;
        griditems[7].name = "eight";
        griditems[7].colorno = 0;
        
        // GridView�I�u�W�F�N�g���擾.
        GridView gridview1 = (GridView)findViewById(R.id.gridview1);	// findViewById��gridview1���擾.
        
        // GridItemAdapter��adapter�𐶐�����, gridview1��adapter��griditems��R�t����.
        GridItemAdapter adapter = new GridItemAdapter(this, R.layout.grid_item, griditems);	// GridItemAdapter�R���X�g���N�^��GridView�̃A�C�e���e���v���[�g��grid_item�ƃO���b�h�f�[�^��griditems���Z�b�g.
        gridview1.setAdapter(adapter);	// gridview1.setAdapter��adapter���Z�b�g����, GridView��Adapter��R�t����.
    }
}

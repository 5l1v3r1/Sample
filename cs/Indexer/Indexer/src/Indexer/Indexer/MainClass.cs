// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // Class1�I�u�W�F�N�g�̍쐬.
        Class1 c1 = new Class1(5);  // �v�f��5��Class1�I�u�W�F�N�gc1�𐶐�.

        // �l�̐ݒ�.
        c1[0] = 1;  // 0�Ԗڂ�1���Z�b�g.
        c1[-3] = 5;  // -3�Ԗڂ�5���Z�b�g.(�G���[)
        c1[2] = 8;  // 2�Ԗڂ�8���Z�b�g.
        c1[100] = 10; // 100�Ԗڂ�10���Z�b�g.(�G���[)
        c1[4] = -5; // 4�Ԗڂ�-5���Z�b�g.(�G���[)

        // �l�̎擾
        int[] v = new int[5];
        v[0] = c1[0]; // c1��0�Ԗڂ�v��0�ԖڂɊi�[.
        v[1] = c1[-2];  // c1��-2�Ԗڂ�v��1�ԖڂɊi�[.(�G���[)
        v[2] = c1[15];  // c1��15�Ԗڂ�v��2�ԖڂɊi�[.(�G���[)
        v[3] = c1[2];   // c1��2�Ԗڂ�v��3�ԖڂɊi�[.
        v[4] = c1[4];   // c1��4�Ԗڂ�v��4�ԖڂɊi�[.(c1[4]�̐ݒ�Ŋ��ɃG���[.)

        // c1�̒l�̏o��.
        for (int i = 0; i < 5; i++)
        {
            Console.WriteLine("c1[" + i + "] = " + c1[i]);
        }

        // v�̒l�̏o��.
        for (int i = 0; i < 5; i++)
        {
            Console.WriteLine("v[" + i + "] = " + v[i]);
        }

    }

}
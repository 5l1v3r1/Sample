// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �z��̏o��(�v�f��5).
        Class1 five = new Class1(5);  // �v�f��5��Class1�I�u�W�F�N�gfive.
        five.print(); // �z��̏o��.

        // �z��̏o��(�v�f��10).
        Class1 ten = new Class1(10);  // �v�f��10��Class1�I�u�W�F�N�gten.
        ten.print(); // �z��̏o��.

    }

}
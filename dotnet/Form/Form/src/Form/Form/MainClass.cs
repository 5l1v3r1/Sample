// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Windows.Forms; // Windows�t�H�[��(System.Windows.Forms���O���)

// MainClass�̒�`
class MainClass
{
    // Main���\�b�h�̒�`
    static void Main()
    {
        // �t�H�[���I�u�W�F�N�g�̍쐬
        Form frm = new Form();  // Form�I�u�W�F�N�gfrm�̃C���X�^���X�쐬
        frm.Text = "Form";  // frm��Text(�E�B���h�E�^�C�g��)��"Form"�Ƃ���.

        // �E�B���h�E�̍쐬�ƃA�v���P�[�V�����̎��s.
        Application.Run(frm);    // frm��\������A�v�������s.
    }
}
// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Diagnostics;   // �V�X�e���v���Z�X��C�x���g���O�Ƃ̑Θb���邽�߂̃N���X.(System.Diagnostics���O���)

// MainClass�̒�`
class MainClass
{
    // Main���\�b�h�̒�`
    static void Main()
    {

        // Process�I�u�W�F�N�g�̐���.
        Process p = new Process();  // Process�I�u�W�F�N�gp�𐶐�.

        // Process.StartInfo�v���p�e�B�ŏڍׂ�ݒ�.
        p.StartInfo.FileName = "notepad";   // ���s�t�@�C������"notepad".
        p.StartInfo.Arguments = "test.txt"; // ������"test.txt".

        // ���s.
        p.Start();  // p.Start�Ŏ��s.

    }

}
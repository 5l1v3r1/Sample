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
        p.StartInfo.FileName = Environment.GetEnvironmentVariable("ComSpec");   // cmd.exe�̃p�X���w��.
        p.StartInfo.Arguments = @"/C ping yahoo.co.jp";    // "/C"�͈ȍ~�ɑ�����������R�}���h�Ƃ��Ď��s����̂�, cmd.exe��"ping yahoo.co.jp"�����s�����.
        p.StartInfo.UseShellExecute = false;    // ShellExecute���g��Ȃ�.
        p.StartInfo.CreateNoWindow = true;  // �E�B���h�E��\�����Ȃ�.
        p.StartInfo.RedirectStandardOutput = true;  // �W���o�͂����_�C���N�g����.

        // ���s.
        p.Start();  // p.Start�Ŏ��s.
        string result = p.StandardOutput.ReadToEnd();   // �W���o�͂�S�ēǂݎ��, result�Ɋi�[.
        p.WaitForExit();    // p.WaitForExit�ŏI���܂ő҂�.
        p.Close();  // ���\�[�X�̉��.
        Console.WriteLine("-----" + result + "-----");  // result�̏o��.

    }

}
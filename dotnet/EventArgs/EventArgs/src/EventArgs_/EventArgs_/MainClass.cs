// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�̒�`
{

    // Main���\�b�h�̒�`
    static void Main()
    {

        // ���͂���ƃC�x���g����������R���\�[���N���XEventConsole.
        EventConsole eventConsole = new EventConsole("END");  // EventConsole�I�u�W�F�N�geventConsole�̐���.("END"�����͂��ꂽ�甲����.)
        eventConsole.ReadLineText += EventConsole_ReadLineText; // �C�x���g�n���h���̒ǉ�.
        eventConsole.EventLoop();   // �C�x���g���[�v�ɓ���.

    }

    // �C�x���g�n���h��
    public static void EventConsole_ReadLineText(object sender, EventConsoleEventArgs e)
    {

        // sender�̖��O���o��.
        Console.WriteLine("sender = " + sender.GetType().Name); // sender.GetType().Name�Ŗ��O���o��.
        // e�̃v���p�e�B���o��.
        Console.WriteLine("e.Line = " + e.Line);    // e.Line���o��.
        Console.WriteLine("e.Result = " + e.Result);    // e.Result���o��.

    }

}
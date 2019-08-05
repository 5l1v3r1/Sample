// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// �C�x���g�R���\�[���N���X
public class EventConsole   // EventConsole�N���X�̒�`
{

    // �����o�̒�`
    public delegate void ReadLineTextHandler(object sender, EventConsoleEventArgs e);   // ReadLineTextHandler�f���Q�[�g
    public event ReadLineTextHandler ReadLineText;  // ReadLineText�C�x���g
    private string target = ""; // �Ώە�����target
    public EventConsole(string target)  // �R���X�g���N�^
    {

        // �����o�̏�����.
        this.target = target;   // �����������o�ɃZ�b�g.

    }
    public void EventLoop() // EventLoop���\�b�h
    {

        // ���͕�������`�F�b�N.
        while (true)
        {

            // 1�s�ǂݎ��.
            string line = Console.ReadLine();   // Console.ReadLine�œǂݎ��.
            EventConsoleEventArgs args = new EventConsoleEventArgs();   // EventConsoleEventArgs�I�u�W�F�N�gargs�𐶐�.
            args.Line = line;   // args.Line��line���i�[.
            if (line == target) // line��target������.
            {
                args.Result = true; // args.Line��true.
                ReadLineText(this, args);   // ReadLineText��this��args��n��.
                break; // ���[�v�𔲂���.
            }
            else
            {
                args.Result = false;    // args.Line��false.
                ReadLineText(this, args);   // ReadLineText��this��args��n��.
            }

        }

    }

}
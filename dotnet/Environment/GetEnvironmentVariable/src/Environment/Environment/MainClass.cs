// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// MainClass�̒�`
class MainClass
{

    // Main���\�b�h�̒�`
    static void Main()
    {

        // ���ϐ��̒l�̎擾.
        string cmd;     // ComSpec(cmd.exe�̃p�X).
        string os;      // OS(OS��).
        string path;    // Path(����̃p�X).

        // ComSpec
        cmd = Environment.GetEnvironmentVariable("ComSpec");    // ���ϐ�ComSpec�̒l��cmd�Ɋi�[.

        // OS
        os = Environment.GetEnvironmentVariable("OS");  // ���ϐ�OS�̒l��cmd�Ɋi�[.

        // Path
        path = Environment.GetEnvironmentVariable("Path");  // ���ϐ�Path�̒l��path�Ɋi�[.

        // �o��.
        Console.WriteLine("cmd = " + cmd);      // cmd���o��.
        Console.WriteLine("os = " + os);        // os���o��.
        Console.WriteLine("path = " + path);    // path���o��.

    }

}
// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// MainClass�̒�`
class MainClass
{

    // Main���\�b�h�̒�`
    static void Main()
    {

        // �o�[�W�������̎擾.
        string version = Environment.OSVersion.ToString();  // OSVersion�𕶎���Ŏ擾.(OSVersion��OperatingSystem�^�Ȃ̂�ToString�ŕ�����.)

        // version�̏o��.
        Console.WriteLine("version = " + version);  // version���o��.

    }

}
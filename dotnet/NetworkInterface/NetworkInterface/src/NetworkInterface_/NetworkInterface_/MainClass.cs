// ���O��Ԃ̓o�^
using System;                           // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Net.NetworkInformation;   // �l�b�g���[�N���֘A�N���X(System.Net.NetworkInformation���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �l�b�g���[�N�C���^�[�t�F�C�X�ꗗ���擾.
        NetworkInterface[] ni = NetworkInterface.GetAllNetworkInterfaces(); // NetworkInterface.GetAllNetworkInterfaces�ł��ׂẴC���^�[�t�F�C�X�z����擾.

        // �l�b�g���[�N�C���^�[�t�F�C�X�̖��O���ꗗ�ŕ\��.
        foreach (NetworkInterface n in ni)  // foreac��ni����n�����o��.
        {

            // �l�b�g���[�N�C���^�[�t�F�C�X�̖��O���o��.
            Console.WriteLine("n.Name = " + n.Name);    // n.Name���o��.

        }

    }

}
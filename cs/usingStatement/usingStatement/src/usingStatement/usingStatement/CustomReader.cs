// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.IO;    // �t�@�C�����o�͂ƃf�[�^�X�g���[��(System.IO���O���)

// CustomReader�̒�`
class CustomReader : IDisposable
{
    // �t�B�[���h�̒�`
    private string filename1 = "";      // 1�ڂ̃t�@�C����string�^filename1��""�ŏ�����.
    private string filename2 = "";      // 2�ڂ̃t�@�C����string�^filename2��""�ŏ�����.
    private StreamReader sr1 = null;    // 1�ڂ̃X�g���[��StreamReader�^sr1��null�ŏ�����.
    private StreamReader sr2 = null;    // 2�ڂ̃X�g���[��StreamReader�^sr2��null�ŏ�����.
    public string text1 = "";           // 1�ڂ̃e�L�X�gstring�^text1��""�ŏ�����.
    public string text2 = "";           // 2�ڂ̃e�L�X�gstring�^text2��""�ŏ�����.

    // ���\�b�h�̒�`
    // �����t���R���X�g���N�^
    public CustomReader(string filename1, string filename2)
    {
        // �����o�̃Z�b�g.
        this.filename1 = filename1; // �����o��filename1�Ɉ�����filename1���Z�b�g.
        this.filename2 = filename2; // �����o��filename2�Ɉ�����filename2���Z�b�g.
    }

    // 2�̃t�@�C���̓��e�����ׂēǂݍ��ރ��\�b�hReadAll.
    public bool ReadAll()
    {
        // �e�L�X�g�̓ǂݍ���.
        sr1 = new StreamReader(filename1);  // StreamReader�I�u�W�F�N�g���쐬��, sr1�Ɋi�[.
        text1 = sr1.ReadToEnd();    // sr1.ReadToEnd�œǂݍ��񂾓��e��text1�Ɋi�[.
        sr2 = new StreamReader(filename2);  // StreamReader�I�u�W�F�N�g���쐬��, sr2�Ɋi�[.
        text2 = sr2.ReadToEnd();    // sr2.ReadToEnd�œǂݍ��񂾓��e��text2�Ɋi�[.
        return true;    // �����Ȃ�true.
    }

    // ���\�[�X������\�b�hDispose(IDispose�̃����o�̃I�[�o�[���C�h.)
    public void Dispose()
    {
        // ���\�[�X�������.
        Console.WriteLine("Dispose");   // "Dispose"���o��.
        if (sr2 != null)    // sr2��null�łȂ����.
        {
            // �t�@�C�������.
            sr2.Close();    // sr2.Close�ŕ���.
            sr2 = null; // sr2��null���Z�b�g.
            Console.WriteLine("sr2 closed!");   // "sr2 closed!"���o��.
        }
        if (sr1 != null)    // sr1��null�łȂ����.
        {
            // �t�@�C�������.
            sr1.Close();    // sr1.Close�ŕ���.
            sr1 = null; // sr1��null���Z�b�g.
            Console.WriteLine("sr1 closed!");   // "sr1 closed!"���o��.
        }
    }
}
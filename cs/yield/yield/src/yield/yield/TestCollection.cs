// ���O��Ԃ̓o�^
using System;               // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Collections;   // �R���N�V�����N���X(System.Collections���O���)

// �e�X�g�R���N�V�����N���X
class TestCollection : IEnumerable  // TestCollection�N���X�̒�`(IEnumerable�C���^�[�t�F�C�X������.)
{

    // IEnumerator��Ԃ����\�b�hGetEnumerator.
    public IEnumerator GetEnumerator()
    {

        // 1, 3, 5, 7, 9��v�f�Ƃ���R���N�V������yield�Ő���.
        Console.WriteLine("yield return 1 before.");    // "yield return 1 before."���o��.
        yield return 1; // 1��ڂ�yield return��1��Ԃ���, foreach��1�Ԗڂ̗v�f�����o���ꂽ��, return 1�����s�����.
        Console.WriteLine("yield return 3 before.");    // "yield return 3 before."���o��.
        yield return 3; // 2��ڂ�yield return��3��Ԃ���, foreach��2�Ԗڂ̗v�f�����o���ꂽ��, return 3�����s�����.
        Console.WriteLine("yield return 5 before.");    // "yield return 5 before."���o��.
        yield return 5; // 3��ڂ�yield return��5��Ԃ���, foreach��3�Ԗڂ̗v�f�����o���ꂽ��, return 5�����s�����.
        Console.WriteLine("yield return 7 before.");    // "yield return 7 before."���o��.
        yield return 7; // 4��ڂ�yield return��7��Ԃ���, foreach��4�Ԗڂ̗v�f�����o���ꂽ��, return 7�����s�����.
        Console.WriteLine("yield return 9 before.");    // "yield return 9 before."���o��.
        yield return 9; // 5��ڂ�yield return��9��Ԃ���, foreach��5�Ԗڂ̗v�f�����o���ꂽ��, return 9�����s�����.

    }

}
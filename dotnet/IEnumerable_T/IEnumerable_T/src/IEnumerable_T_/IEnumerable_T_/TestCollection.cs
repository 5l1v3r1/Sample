// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Collections;   // �R���N�V�����N���X(System.Collections���O���)
using System.Collections.Generic;   // �W�F�l���b�N�R���N�V�����N���X(System.Collections.Generic���O���)

// �e�X�g�R���N�V�����N���X
public class TestCollection<T> : IEnumerable<T>  // TestCollection<T>�N���X�̒�`(IEnumerable<T>�C���^�[�t�F�C�X������.)
{

    // �����o�t�B�[���h
    private T[] ary;    // T�̔z��ary.
    private int size;   // ary�̃T�C�Ysize.

    // �R���X�g���N�^
    public TestCollection(int size)
    {
        this.size = size;
        ary = new T[size];
    }

    // �l�̃Z�b�g
    public void Set(int i, T val)
    {
        ary[i] = val;
    }

    // IEnumerator<T>��Ԃ����\�b�hGetEnumerator.
    public IEnumerator<T> GetEnumerator()
    {
        // T[]��ary��GetEnumerator��IEnumerator�Ȃ̂�, ���̂܂ܕԂ��Ȃ��̂�yield�ɂ�����Ԃ���.
        foreach (T v in ary)
        {
            yield return v;
        }
    }

    // ��W�F�l���b�N���錾���Ȃ��Ƃ����Ȃ�.
    IEnumerator IEnumerable.GetEnumerator()
    {
        return this.GetEnumerator();    // IEnumerator<T>���̕���Ԃ�.
    }

}
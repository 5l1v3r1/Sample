// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// �f���Q�[�g�̐錾
delegate BaseClass DelegateCreateBase();    // ��������BaseClass��Ԃ��f���Q�[�g.

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �f���Q�[�g�̏�����.
        DelegateCreateBase dcb = null;  // dcb��null�ŏ�����.

        // �f���Q�[�g�Ɋ��N���X�������\�b�h��ǉ�.
        dcb += new DelegateCreateBase(CreateBase);    // dcb��CreateBase��ǉ�.

        // �ǉ��������Ƃ��o��.
        Console.WriteLine("Add CreateBase to dcb!");    // "Add CreateBase to dcb!"�Əo��.

        // BaseClass�̏�����.
        BaseClass bc = null;    // bc��null�ŏ�����.

        // BaseClass�̃C���X�^���X��BaseClass�I�u�W�F�N�g�Ŏ󂯎��.
        bc = dcb();  // dcb���Ăяo��, bc���󂯎��.

        // ���O�̊m�F.
        Console.WriteLine("bc.Name = " + bc.Name);  // bc.Name���o��.

        // �����قǂ̃��\�b�h������.
        dcb -= CreateBase;  // dcb����CreateBase���폜.

        // �f���Q�[�g�ɔh���N���X�������\�b�h��ǉ�.
        dcb += new DelegateCreateBase(CreateDerived);    // dcb��CreateDerived��ǉ�.

        // �ǉ��������Ƃ��o��.
        Console.WriteLine("Add CreateDerived to dcb!");    // "Add CreateDerived to dcb!"�Əo��.

        // bc�̍ď�����.
        bc = null;    // bc��null�ŏ�����.

        // DerivedClass�̃C���X�^���X��BaseClass�I�u�W�F�N�g�Ŏ󂯎��.
        bc = dcb();  // dcb���Ăяo��, bc���󂯎��.

        // ���O�̊m�F.
        Console.WriteLine("bc.Name = " + bc.Name);  // bc.Name���o��.

    }

    // BaseClass�I�u�W�F�N�g�𐶐����郁�\�b�h.
    static BaseClass CreateBase()
    {

        // BaseClass�I�u�W�F�N�g��b�̐���.
        BaseClass b = new BaseClass();  // BaseClass�I�u�W�F�N�g��b�Ɋi�[.

        // b�̏�����.
        b.Name = "Taro";    // b.Name��"Taro";

        // b��Ԃ�.
        Console.WriteLine("Return BaseClass Object!");  // "Return BaseClass Object!"���o��.
        return b;   // b��Ԃ�.

    }

    // DerivedClass�I�u�W�F�N�g�𐶐����郁�\�b�h.
    static DerivedClass CreateDerived()
    {

        // DerivedClass�I�u�W�F�N�g��d�̐���.
        DerivedClass d = new DerivedClass();  // DerivedClass�I�u�W�F�N�g��d�Ɋi�[.

        // d�̏�����.
        d.Name = "Jiro";    // d.Name��"Jiro".
        d.Address = "Osaka";    // d.Address��"Osaka".

        // d��Ԃ�.
        Console.WriteLine("Return DerivedClass Object!");  // "Return DerivedClass Object!"���o��.
        return d;   // d��Ԃ�.

    }

}
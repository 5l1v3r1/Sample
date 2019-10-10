// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// �f���Q�[�g�̐錾
delegate void DelegateSetDerived(DerivedClass dc);  // DerivedClass���Z�b�g����f���Q�[�g.

// ���C���N���X
class MainClass // MainClass�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �f���Q�[�g�̏�����.
        DelegateSetDerived dsd = null;  // dsd��null�ŏ�����.

        // �f���Q�[�g�ɔh���N���X���Z�b�g���郁�\�b�h��ǉ�.
        dsd += new DelegateSetDerived(SetDerived);  // dsd��SetDerived��ǉ�.

        // �ǉ��������Ƃ��o��.
        Console.WriteLine("Add SetDerived to dsd!");    // "Add SetDerived to dsd!"�Əo��.

        // DerivedClass�̏�����.
        DerivedClass dc = new DerivedClass();   // DerivedClass�I�u�W�F�N�gdc�𐶐�.
        dc.Name = "Jiro";   // dc.Name��"Jiro"���Z�b�g.
        dc.Address = "Osaka";   // dc.Address��"Osaka"���Z�b�g.

        // dc��dsd�ɓn��.
        dsd(dc);    // dsd��dc��n��.

        // �����قǂ̃��\�b�h������.
        dsd -= SetDerived;  // dsd����SetDerived���폜.

        // �f���Q�[�g�Ɋ��N���X���Z�b�g���郁�\�b�h��ǉ�.
        dsd += new DelegateSetDerived(SetBase);  // dsd��SetBase��ǉ�.

        // �ǉ��������Ƃ��o��.
        Console.WriteLine("Add SetBase to dsd!");   // "Add SetBase to dsd!"�Əo��.

        // BaseClass�̏�����.
        //BaseClass bc = new BaseClass(); // BaseClass�I�u�W�F�N�gbc���쐬.
        //bc.Name = "Taro";   // �����ł�"Taro"���Z�b�g.

        // bc��dsd�ɓn��.
        //dsd(bc);    // dsd��bc��n��.

        // DerivedClass�̍ď�����.(�ǂ���BaseClass��n����킯�ł͂Ȃ��炵��.)
        dc = new DerivedClass();    // DerivedClass�I�u�W�F�N�gdc�𐶐�.
        dc.Name = "Taro";   // �����ł�"Taro"���Z�b�g����.

        // dc��dsd�ɓn��.(BaseClass�I�u�W�F�N�gbc��n������r���h�G���[.)
        dsd(dc);    // dsd��dc��n��.

    }

    // DerivedClass�I�u�W�F�N�g���Z�b�g���郁�\�b�h.
    static void SetDerived(DerivedClass dc)
    {

        // dc���󂯎�������Ƃ��o��.
        Console.WriteLine("Set DerivedClass Object!");  // "Set DerivedClass Object!"�Əo��.

        // �����o�̏o��.
        Console.WriteLine("dc.Name = " + dc.Name);  // dc.Name���o��.
        Console.WriteLine("dc.Address = " + dc.Address);    // dc.Address���o��.

    }

    // BaseClass�I�u�W�F�N�g���Z�b�g���郁�\�b�h.
    static void SetBase(BaseClass bc)
    {

        // bc���󂯎�������Ƃ��o��.
        Console.WriteLine("Set BaseClass Object!"); // "Set BaseClass Object!"�Əo��.

        // �����o�̏o��.
        Console.WriteLine("bc.Name = " + bc.Name);  // bc.Name���o��

    }

}
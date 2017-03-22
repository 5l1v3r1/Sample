// ���O��Ԃ̓o�^
using System.ServiceProcess;    // �T�[�r�X�v���Z�X�N���X(System.ServiceProcess���O���)
using System.Diagnostics;   // �V�X�e���v���Z�X��C�x���g���O�Ƃ̑Θb���邽�߂̃N���X.(System.Diagnostics���O���)

// ���C���N���X
class MainClass : ServiceBase   // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �C�x���g���O�ɏ�������.
        EventLog.WriteEntry("ServiceBase_", "Run before");   // EventLog�̃X�^�e�B�b�N���\�b�hWriteEntry��"ServiceBase_"�Ƃ����\�[�X��"Run before"�Ə�������.

        // �T�[�r�X�J�n.
        ServiceBase.Run(new MainClass()); //  ServiceBase.Run��MainClass�I�u�W�F�N�g�C���X�^���X��n���ăT�[�r�X�N��.

        // �C�x���g���O�ɏ�������.
        EventLog.WriteEntry("ServiceBase_", "Run after");   // EventLog�̃X�^�e�B�b�N���\�b�hWriteEntry��"ServiceBase_"�Ƃ����\�[�X��"Run after"�Ə�������.

    }

    // �R���X�g���N�^
    public MainClass()
    {

        // �T�[�r�X�̏�����.
        CanStop = true; // ��~�\�ɂ���.
        ServiceName = "ServiceBase_";   // �T�[�r�X����"ServiceBase_".

    }

    // �T�[�r�X�J�n��
    protected override void OnStart(string[] args){
        
        // �C�x���g���O�ɏ�������.
        EventLog.WriteEntry("ServiceBase_", "OnStart");   // EventLog�̃X�^�e�B�b�N���\�b�hWriteEntry��"ServiceBase_"�Ƃ����\�[�X��"OnStart"�Ə�������.

    }

    // �T�[�r�X��~��
    protected override void OnStop()
    {

        // �C�x���g���O�ɏ�������.
        EventLog.WriteEntry("ServiceBase_", "OnStop");   // EventLog�̃X�^�e�B�b�N���\�b�hWriteEntry��"ServiceBase_"�Ƃ����\�[�X��"OnStop"�Ə�������.

    }

}
using System;
using System.Collections.Generic;
using System.Text;

//namespace IpcClientChannel_
namespace Ipc_
{
    // �N���C�A���g�ƃT�[�o�ŋ��L����I�u�W�F�N�gRemoteObject
    public class RemoteObject : MarshalByRefObject
    {
        // ���b�Z�[�W�����L.
        private string message; // ���b�Z�[������message.
        public string Message   // message�̎擾�E�ݒ�������v���p�e�BMessage.
        {
            get
            {
                return message;
            }
            set
            {
                message = value;
            }
        }
    }
}
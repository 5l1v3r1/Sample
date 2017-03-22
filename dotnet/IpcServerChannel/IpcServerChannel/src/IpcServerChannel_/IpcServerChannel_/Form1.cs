using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Runtime.Remoting;  // �����[�g(System.Runtime.Remoting���O���)
using System.Runtime.Remoting.Channels; // �`���l��(System.Runtime.Remoting.Channels���O���)
using System.Runtime.Remoting.Channels.Ipc; // IPC(System.Runtime.Remoting.Channels.Ipc���O���)
using System.Text;
using System.Windows.Forms;

//namespace IpcServerChannel_
namespace Ipc_
{
    public partial class Form1 : Form
    {
        // �����o�t�B�[���h�̒�`
        public RemoteObject remoteObj;  // ���L����RemoteObject�^remoteObj.

        // �R���X�g���N�^
        public Form1()
        {
            InitializeComponent();

            // IPC�T�[�o�[�`�����l�����쐬.
            IpcServerChannel server = new IpcServerChannel("ipcserver");    // �|�[�g����"ipcserver"��IpcServerChannel�I�u�W�F�N�gserver�𐶐�.

            // �`�����l����o�^.
            ChannelServices.RegisterChannel(server, true);    // ChannelServices.RegisterChannel�Ń`�����l��server��o�^.

            // �����[�g�I�u�W�F�N�g�̍쐬.
            remoteObj = new RemoteObject(); // RemoteObject�I�u�W�F�N�g�𐶐���, remoteObj�Ɋi�[.

            // �����[�g�I�u�W�F�N�g�̌��J.
            RemotingServices.Marshal(remoteObj, "message", typeof(RemoteObject));   //  RemotingServices.Marshal��remoteObj�����J.("ipc://ipcserver/message"�Ƃ���URI�Ō��J�����.)
        }

        // button1���N���b�N���ꂽ��.
        private void button1_Click(object sender, EventArgs e)
        {
            // ���͂��ꂽ�e�L�X�g�������[�g�I�u�W�F�N�g�Ɋi�[.
            remoteObj.Message = textBox1.Text;  // textBox1.Text��remoteObj.Message�Ɋi�[.
        }
    }
}
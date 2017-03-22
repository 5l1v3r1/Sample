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

//namespace IpcClientChannel_
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

            // IPC�N���C�A���g�`�����l�����쐬.
            IpcClientChannel client = new IpcClientChannel();   // IpcClientChannel�I�u�W�F�N�gclient���쐬.

            // �`�����l����o�^.
            ChannelServices.RegisterChannel(client, true);  // ChannelServices.RegisterChannel�Ń`�����l��client��o�^.
        }

        // button1���N���b�N���ꂽ��.
        private void button1_Click(object sender, EventArgs e)
        {
            // �����[�g�I�u�W�F�N�g����e�L�X�g���擾.
            remoteObj = (RemoteObject)Activator.GetObject(typeof(RemoteObject), "ipc://ipcserver/message");   // Activator.GetObject�Ŏ擾����RemoteObject�ɃL���X�g����remoteObj�Ɋi�[.
            textBox1.Text = remoteObj.Message;  // textBox1.Text��remoteObj.Message���i�[.
        }
    }
}
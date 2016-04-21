using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace ListView_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // ���X�g�r���[�ɃA�C�e����ǉ�.
            string[] item = new string[3];  // string�z��item(�v�f��3)��p��.
            item[0] = textBox1.Text;    // item[0]��textBox1.Text(Name�̃e�L�X�g)���Z�b�g.
            item[1] = textBox2.Text;    // item[1]��textBox2.Text(Age�̃e�L�X�g)���Z�b�g.
            item[2] = textBox3.Text;    // item[2]��textBox3.Text(Address�̃e�L�X�g)���Z�b�g.
            listView1.Items.Add(new ListViewItem(item)); // listView1.Items.Add�ŐV���ɍ쐬����ListViewItem�̃C���X�^���X��ǉ�.(ListViewItem�̃R���X�g���N�^��item��n��.)
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // �I������Ă���s(�����s�̉\��������̂ł��̂����̍ŏ��̍s)���擾.
            ListViewItem lvitem = listView1.SelectedItems[0];  // listView1.SelectedItems[0]�őI������Ă���s�̂����ŏ��̍s���擾��, ListViewItem�^lvitem�Ɋi�[.
            textBox1.Text = lvitem.SubItems[0].Text; // lvitem.SubItems[0].Text��0��ڂ̃e�L�X�g�����o����textBox1.Text�ɓn��.
            textBox2.Text = lvitem.SubItems[1].Text; // lvitem.SubItems[1].Text��1��ڂ̃e�L�X�g�����o����textBox2.Text�ɓn��.
            textBox3.Text = lvitem.SubItems[2].Text; // lvitem.SubItems[2].Text��2��ڂ̃e�L�X�g�����o����textBox3.Text�ɓn��.
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // ���X�g�r���[�Ƀw�b�_��ǉ�����.
            listView1.Columns.Add("Name");      // listView1.Columns.Add��"Name"���ǉ�.
            listView1.Columns.Add("Age");       // listView1.Columns.Add��"Age"���ǉ�.
            listView1.Columns.Add("Address");   // listView1.Columns.Add��"Address"���ǉ�.
        }
    }
}
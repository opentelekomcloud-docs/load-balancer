:original_name: elb_ug_ip_0000.html

.. _elb_ug_ip_0000:

IP Address Group (Whitelist or Blacklist)
=========================================

Scenarios
---------

An IP address group is a collection of IP addresses that you can use to manage IP addresses with the same security requirements or whose security requirements change frequently.

If you want to use a whitelist or blacklist for access control, you must select an IP address group. Access from whitelisted or blacklisted IP addresses will be allowed or denied.

An IP address group can be associated with a maximum of 50 listeners.

.. note::

   This function is available in the **eu-de** region, but unavailable in the **eu-nl** region.

Creating an IP Address Group
----------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. In the navigation pane on the left, choose **IP Address Groups**. On the displayed page, click **Create IP Address Group**.

#. Configure the parameters based on :ref:`Table 1 <elb_ug_ip_0000__table3263104318541>`.

   .. _elb_ug_ip_0000__table3263104318541:

   .. table:: **Table 1** Parameter description

      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Parameter             | Description                                                                                                                                                                                                            | Example Value         |
      +=======================+========================================================================================================================================================================================================================+=======================+
      | Name                  | Specifies the name of the IP address group.                                                                                                                                                                            | ipGroup-01            |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | IP Addresses          | Specifies IPv4 IP addresses or CIDR blocks that are added to the whitelist or blacklist for access control.                                                                                                            | 10.168.2.24           |
      |                       |                                                                                                                                                                                                                        |                       |
      |                       | -  Each IP address or CIDR block must be on a separate line and end with a carriage return.                                                                                                                            | 10.168.16.0/24        |
      |                       | -  Each IP address or CIDR block can include a description with a vertical bar (|) separated, for example, 192.168.10.10 \| ECS01. The description is 0 to 255 characters long and cannot contain angle brackets (<>). |                       |
      |                       | -  You can add a maximum of 300 IP addresses and CIDR blocks in each IP address group.                                                                                                                                 |                       |
      |                       |                                                                                                                                                                                                                        |                       |
      |                       | .. note::                                                                                                                                                                                                              |                       |
      |                       |                                                                                                                                                                                                                        |                       |
      |                       |    If the IP address group does not contain any IP address and you have selected whitelist for access control, no IP addresses can access the listener.                                                                |                       |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Description           | Provides supplementary information about the IP address group.                                                                                                                                                         | N/A                   |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+

#. Click **OK**.

Modifying an IP Address Group
-----------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image3| and select the desired region and project.

#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. On the **IP Address Groups** page, locate the IP address group, and click **Modify** in the **Operation** column.

#. Modify the parameters based on :ref:`Table 2 <elb_ug_ip_0000__table20185132813358>`.

   .. _elb_ug_ip_0000__table20185132813358:

   .. table:: **Table 2** Parameters required for creating an IP address group

      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Parameter             | Description                                                                                                                                                                                                                                    | Example Value         |
      +=======================+================================================================================================================================================================================================================================================+=======================+
      | Name                  | Specifies the name of the IP address group.                                                                                                                                                                                                    | ipGroup-01            |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | IP Address            | Specifies IP addresses or CIDR blocks that are added to the whitelist or blacklist for access control.                                                                                                                                         | 10.168.2.24           |
      |                       |                                                                                                                                                                                                                                                |                       |
      |                       | -  Each IP address or CIDR block must be on a separate line and end with a carriage return.                                                                                                                                                    | 10.168.16.0/24        |
      |                       | -  Each line can include a description with a vertical bar (|) separated from the IP address or CIDR block, for example, 192.168.10.10 \| ECS01. The description can contain up to 255 characters long and cannot contain angle brackets (<>). |                       |
      |                       | -  You can add a maximum of 300 IP addresses and CIDR blocks in each IP address group.                                                                                                                                                         |                       |
      |                       |                                                                                                                                                                                                                                                |                       |
      |                       | .. note::                                                                                                                                                                                                                                      |                       |
      |                       |                                                                                                                                                                                                                                                |                       |
      |                       |    If the IP address group does not contain any IP address and you have selected whitelist for access control, no IP addresses can access the listener.                                                                                        |                       |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Description           | Provides supplementary information about the IP address group.                                                                                                                                                                                 | N/A                   |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+

#. Click **OK**.

Deleting an IP Address Group
----------------------------

If you no longer need an IP address group, you can delete it. If an IP address group has been associated with a listener, disassociate the IP address group from the listener before the deletion.

#. Log in to the management console.
#. In the upper left corner of the page, click |image5| and select the desired region and project.
#. Hover on |image6| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. On the **IP Address Groups** page, locate the IP address group, and click **Delete** in the **Operation** column.
#. Click **Yes**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001417088430.png
.. |image3| image:: /_static/images/en-us_image_0000001211126503.png
.. |image4| image:: /_static/images/en-us_image_0000001417088430.png
.. |image5| image:: /_static/images/en-us_image_0000001211126503.png
.. |image6| image:: /_static/images/en-us_image_0000001417088430.png

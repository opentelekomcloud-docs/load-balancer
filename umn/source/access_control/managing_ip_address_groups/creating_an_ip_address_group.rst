:original_name: elb_ug_ip_0000.html

.. _elb_ug_ip_0000:

Creating an IP Address Group
============================

.. _elb_ug_ip_0000__section1143912015382:

IP Address Group Overview
-------------------------

An IP address group is a collection of IP addresses that you can use to manage IP addresses with the same security requirements or whose security requirements change frequently.

ELB allows you to use a whitelist or blacklist for access control. If you want to configure an :ref:`access control <elb_03_0003>` policy, you must select an IP address group.

-  **Whitelist**: Only IP addresses in the IP address group can access the listener. If the IP address group does not contain any IP address and you have selected whitelist for access control, no IP addresses can access the listener.
-  **Blacklist**: IP addresses in the IP address group are denied to access the listener. If the IP address group does not contain any IP address and you have selected blacklist for access control, all IP addresses can access the listener.

Constraints
-----------

-  By default, you can create a maximum of 50 IP address groups.
-  An IP address group can be associated with a maximum of 50 listeners.

Procedure
---------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. In the navigation pane on the left, choose **Elastic Load Balance** > **IP Address Groups**.

#. On the displayed page, click **Create IP Address Group**.

#. Configure the parameters based on :ref:`Table 1 <elb_ug_ip_0000__table3263104318541>`.

   .. _elb_ug_ip_0000__table3263104318541:

   .. table:: **Table 1** Parameters required for creating an IP address group

      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Parameter             | Description                                                                                                                                                                                                            | Example Value         |
      +=======================+========================================================================================================================================================================================================================+=======================+
      | Name                  | Specifies the name of the IP address group.                                                                                                                                                                            | ipGroup-01            |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | IP Addresses          | Specifies IPv4 or IPv6 IP addresses or CIDR blocks that are added to the whitelist or blacklist for access control.                                                                                                    | 10.168.2.24           |
      |                       |                                                                                                                                                                                                                        |                       |
      |                       | -  Each IP address or CIDR block must be on a separate line and end with a carriage return.                                                                                                                            | 10.168.16.0/24        |
      |                       | -  Each IP address or CIDR block can include a description with a vertical bar (|) separated, for example, 192.168.10.10 \| ECS01. The description is 0 to 255 characters long and cannot contain angle brackets (<>). |                       |
      |                       | -  You can add a maximum of 300 IP addresses and CIDR blocks in each IP address group.                                                                                                                                 |                       |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Description           | Provides supplementary information about the IP address group.                                                                                                                                                         | ``-``                 |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+

#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png

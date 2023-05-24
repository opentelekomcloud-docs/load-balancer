:original_name: en-us_topic_0015479967.html

.. _en-us_topic_0015479967:

Creating a Shared Load Balancer
===============================

Prerequisites
-------------

You have prepared everything required for creating a load balancer. For details, see :ref:`Preparations for Creating a Load Balancer <elb_ug_fz_0004>`.

Load balancers receive requests from clients and route the requests to backend servers, which answer to these requests over the private network.

Constraints and Limitations
---------------------------

-  After a load balancer is created, the VPC cannot be changed. If you want to change the VPC, create another load balancer and select the VPC during creation.
-  To ping the IP address of a load balancer, you need to add a listener and associate a backend server to it.

Procedure
---------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. On the **Load Balancers** page, click **Create Elastic Load Balancer**. Configure the parameters based on :ref:`Table 1 <en-us_topic_0015479967__table1312515231668>`.

   .. _en-us_topic_0015479967__table1312515231668:

   .. table:: **Table 1** Parameters for creating a shared load balancer

      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
      | Parameter             | Description                                                                                                                                                                                          | Example Value                     |
      +=======================+======================================================================================================================================================================================================+===================================+
      | Type                  | Specifies the type of the load balancer.                                                                                                                                                             | Shared                            |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
      | Region                | Specifies the region. Resources in different regions cannot communicate with each other over internal networks. For lower network latency and faster access to resources, select the nearest region. | N/A                               |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
      | Network Type          | Specifies the network type of a load balancer.                                                                                                                                                       | Private network                   |
      |                       |                                                                                                                                                                                                      |                                   |
      |                       | -  **Public network**: The load balancer routes requests from the clients to backend servers over the Internet.                                                                                      |                                   |
      |                       | -  **Private network**: The load balancer routes requests from the clients to backend servers in the same VPC.                                                                                       |                                   |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
      | VPC                   | Specifies the VPC where the load balancer works.                                                                                                                                                     | N/A                               |
      |                       |                                                                                                                                                                                                      |                                   |
      |                       | Select an existing VPC or create one.                                                                                                                                                                |                                   |
      |                       |                                                                                                                                                                                                      |                                   |
      |                       | For more information about VPC, see the *Virtual Private Cloud User Guide*.                                                                                                                          |                                   |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
      | Subnet                | Specifies the subnet that the load balancer belongs to.                                                                                                                                              | N/A                               |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
      | Private IP Address    | Specifies how you want the IP address to be assigned.                                                                                                                                                | Automatically-assigned IP address |
      |                       |                                                                                                                                                                                                      |                                   |
      |                       | -  **Automatically-assigned IP address**: The system automatically assigns an IPv4 address to the load balancer.                                                                                     |                                   |
      |                       | -  **Manually-specified IP address**: Manually specify an IPv4 address to the load balancer.                                                                                                         |                                   |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
      | EIP                   | Specifies the public IP address that will be bound to the load balancer for receiving and forwarding requests over the Internet.                                                                     | New EIP                           |
      |                       |                                                                                                                                                                                                      |                                   |
      |                       | The following options are available:                                                                                                                                                                 |                                   |
      |                       |                                                                                                                                                                                                      |                                   |
      |                       | -  **New EIP**: The system will automatically assign an EIP.                                                                                                                                         |                                   |
      |                       |                                                                                                                                                                                                      |                                   |
      |                       | -  **Use existing**: Select an existing EIP.                                                                                                                                                         |                                   |
      |                       |                                                                                                                                                                                                      |                                   |
      |                       |    The optimal **5_bgp** EIP is recommended.                                                                                                                                                         |                                   |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
      | Billed By             | Specifies the bandwidth type of the EIP.                                                                                                                                                             | Dedicated                         |
      |                       |                                                                                                                                                                                                      |                                   |
      |                       | **Traffic**: You specify the maximum bandwidth and pay for the total traffic you use.                                                                                                                |                                   |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
      | Bandwidth             | Specifies the bandwidth when a new EIP is used, in the unit of Mbit/s.                                                                                                                               | 10 Mbit/s                         |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
      | Name                  | Specifies the load balancer name.                                                                                                                                                                    | elb-yss0                          |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
      | Description           | Provides supplementary information about the load balancer.                                                                                                                                          | N/A                               |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
      | Tag                   | Identifies load balancers so that they can be easily found. A tag consists of a tag key and a tag value. The tag key marks a tag, and the tag value specifies specific tag content.                  | -  Key: elb_key1                  |
      |                       |                                                                                                                                                                                                      | -  Value: elb-01                  |
      |                       | For details about the naming specifications, see :ref:`Table 2 <en-us_topic_0015479967__table212772311610>`.                                                                                         |                                   |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+

   .. _en-us_topic_0015479967__table212772311610:

   .. table:: **Table 2** Naming rules of load balancer tags

      +-----------------------+------------------------------------------------------------------------------------+-----------------------+
      | Item                  | Requirement                                                                        | Example Value         |
      +=======================+====================================================================================+=======================+
      | Tag key               | -  Cannot be left blank.                                                           | elb_key1              |
      |                       | -  Must be unique for the same load balancer.                                      |                       |
      |                       | -  Can contain a maximum of 36 characters.                                         |                       |
      |                       | -  Can contain only the following character types:                                 |                       |
      |                       |                                                                                    |                       |
      |                       |    -  Uppercase letters                                                            |                       |
      |                       |    -  Lowercase letters                                                            |                       |
      |                       |    -  Digits                                                                       |                       |
      |                       |    -  Special characters, including hyphens (-), underscores (_), and at signs (@) |                       |
      +-----------------------+------------------------------------------------------------------------------------+-----------------------+
      | Tag value             | -  Can contain a maximum of 43 characters.                                         | elb-01                |
      |                       | -  Can contain only the following character types:                                 |                       |
      |                       |                                                                                    |                       |
      |                       |    -  Uppercase letters                                                            |                       |
      |                       |    -  Lowercase letters                                                            |                       |
      |                       |    -  Digits                                                                       |                       |
      |                       |    -  Special characters, including hyphens (-), underscores (_), and at signs (@) |                       |
      +-----------------------+------------------------------------------------------------------------------------+-----------------------+

#. Click **Create Now**.

#. Confirm the configuration and submit your request.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001417088430.png

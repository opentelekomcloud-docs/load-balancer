Creating a Dedicated Load Balancer
==================================

Scenarios
---------

You have prepared everything required for creating a dedicated load balancer. For details, see `Preparations for Creating a Load Balancer <elb_ug_fz_0004.html>`__.

Dedicated load balancers can be created only in the **eu-nl** region. By default, load balancers created in this region are dedicated load balancers.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Click **Create Load Balancer** and configure the parameters based on `Table 1 <#elb_lb_000006__en-us_topic_0172674943_table08421211125410>`__.
   

.. _elb_lb_000006__en-us_topic_0172674943_table08421211125410:

   .. table:: **Table 1** Parameter description

      +---------------------------------------+---------------------------------------+---------------------------------------+
      | **Parameter**                         | **Description**                       | **Example Value**                     |
      +=======================================+=======================================+=======================================+
      | Type                                  | Specifies the type of the load        | Dedicated                             |
      |                                       | balancer.                             |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Region                                | Specifies the region. Resources in    | eu-nl                                 |
      |                                       | different regions cannot communicate  |                                       |
      |                                       | with each other over internal         |                                       |
      |                                       | networks. For lower network latency   |                                       |
      |                                       | and faster access to resources,       |                                       |
      |                                       | select the nearest region.            |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | AZ                                    | Specifies the AZs of the load         | N/A                                   |
      |                                       | balancer. You can deploy the load     |                                       |
      |                                       | balancer in multiple AZs to ensure    |                                       |
      |                                       | service continuity and improve        |                                       |
      |                                       | application reliability. When an AZ   |                                       |
      |                                       | becomes faulty or unavailable,        |                                       |
      |                                       | requests are quickly routed to        |                                       |
      |                                       | backend servers in other AZs.         |                                       |
      |                                       |                                       |                                       |
      |                                       | If backend servers reside in two AZs, |                                       |
      |                                       | for example, AZ 1 and AZ 2, but you   |                                       |
      |                                       | plan to create the load balancer only |                                       |
      |                                       | in AZ 1, Xen ECSs cannot be used as   |                                       |
      |                                       | clients.                              |                                       |
      |                                       |                                       |                                       |
      |                                       | NOTE:                                 |                                       |
      |                                       | If you change the AZs of an existing  |                                       |
      |                                       | load balancer, the load balancer may  |                                       |
      |                                       | fail to route requests for several    |                                       |
      |                                       | seconds. It is recommended that you   |                                       |
      |                                       | plan the AZs in advance, or change    |                                       |
      |                                       | the AZs during off-peak hours when    |                                       |
      |                                       | necessary.                            |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Network Type                          | Specifies the type of the network     | Private IPv4 network                  |
      |                                       | where the load balancer works. You    |                                       |
      |                                       | can select one or more network types. |                                       |
      |                                       |                                       |                                       |
      |                                       | -  **Public IPv4 network**: The load  |                                       |
      |                                       |    balancer routes requests from the  |                                       |
      |                                       |    clients to backend servers over    |                                       |
      |                                       |    the Internet.                      |                                       |
      |                                       | -  **Private IPv4 network**: The load |                                       |
      |                                       |    balancer routes requests from the  |                                       |
      |                                       |    clients to backend servers in a    |                                       |
      |                                       |    VPC.                               |                                       |
      |                                       |                                       |                                       |
      |                                       | NOTE:                                 |                                       |
      |                                       | If you do not select any of the       |                                       |
      |                                       | options, the load balancer cannot     |                                       |
      |                                       | communicate with the clients after it |                                       |
      |                                       | is created. When you are using ELB or |                                       |
      |                                       | testing network connectivity, ensure  |                                       |
      |                                       | that the load balancer has a public   |                                       |
      |                                       | or private IP address bound.          |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | VPC                                   | Specifies the VPC where the load      | vpc-4536                              |
      |                                       | balancer works. You need to configure |                                       |
      |                                       | this parameter regardless of the      |                                       |
      |                                       | selected network type.                |                                       |
      |                                       |                                       |                                       |
      |                                       | Select an existing VPC or create one. |                                       |
      |                                       |                                       |                                       |
      |                                       | For more information about VPC, see   |                                       |
      |                                       | the *Virtual Private Cloud User       |                                       |
      |                                       | Guide*.                               |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Subnet                                | Specifies the subnet where the load   | subnet-4536                           |
      |                                       | balancer will reside.                 |                                       |
      |                                       |                                       |                                       |
      |                                       | You need to configure this parameter  |                                       |
      |                                       | regardless of the selected network    |                                       |
      |                                       | type.                                 |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Public IPv4 network configuration     |                                       |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | EIP                                   | If you select **Public IPv4 network** | N/A                                   |
      |                                       | for **Network Type**, you need to     |                                       |
      |                                       | bind an EIP to the load balancer. Two |                                       |
      |                                       | options are available:                |                                       |
      |                                       |                                       |                                       |
      |                                       | -  **New EIP**: The system will       |                                       |
      |                                       |    assign a new EIP to the load       |                                       |
      |                                       |    balancer.                          |                                       |
      |                                       | -  **Use existing**: Select an        |                                       |
      |                                       |    existing EIP for the load          |                                       |
      |                                       |    balancer.NOTE:                     |                                       |
      |                                       |                                       |                                       |
      |                                       |    -  By default, load balancers      |                                       |
      |                                       |       created in the **eu-nl** region |                                       |
      |                                       |       are dedicated load balancers.   |                                       |
      |                                       |       You can unbind an EIP from a    |                                       |
      |                                       |       dedicated load balancer only on |                                       |
      |                                       |       the ELB console if you no       |                                       |
      |                                       |       longer need the EIP.            |                                       |
      |                                       |    -  If you bind a new EIP to the    |                                       |
      |                                       |       load balancer and specify a     |                                       |
      |                                       |       shared bandwidth, this EIP will |                                       |
      |                                       |       be added to the shared          |                                       |
      |                                       |       bandwidth.                      |                                       |
      |                                       |    -  If you set **EIP** to **New     |                                       |
      |                                       |       EIP** when you create a         |                                       |
      |                                       |       dedicated load balancer in the  |                                       |
      |                                       |       **eu-de** region, the system    |                                       |
      |                                       |       will automatically assign and   |                                       |
      |                                       |       bind a dedicated EIP to the     |                                       |
      |                                       |       load balancer for exclusive     |                                       |
      |                                       |       use. This type of EIPs can be   |                                       |
      |                                       |       assigned only when you create   |                                       |
      |                                       |       dedicated load balancers and    |                                       |
      |                                       |       can only be bound to dedicated  |                                       |
      |                                       |       load balancers. If you set      |                                       |
      |                                       |       **EIP** to **Use existing**,    |                                       |
      |                                       |       you can select one from the     |                                       |
      |                                       |       dedicated EIPs that were        |                                       |
      |                                       |       assigned when you created       |                                       |
      |                                       |       dedicated load balancers and    |                                       |
      |                                       |       have been unbound from the      |                                       |
      |                                       |       dedicated load balancers.       |                                       |
      |                                       |    -  To unbind an EIP from a load    |                                       |
      |                                       |       balancer, locate the load       |                                       |
      |                                       |       balancer and choose **More** >  |                                       |
      |                                       |       **Unbind EIP** in the           |                                       |
      |                                       |       **Operation** column.           |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | EIP Type                              | Specifies the link type (BGP) when a  | Dynamic BGP                           |
      |                                       | new EIP is used.                      |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Private IPv4 network configuration    |                                       |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | IPv4 Address                          | Specifies how you want the IPv4       | Automatically-assigned IP address     |
      |                                       | address to be assigned.               |                                       |
      |                                       |                                       |                                       |
      |                                       | -  **Automatically-assigned IP        |                                       |
      |                                       |    address**: The system              |                                       |
      |                                       |    automatically assigns an IPv4      |                                       |
      |                                       |    address to the load balancer.      |                                       |
      |                                       | -  **Manually-specified IP address**: |                                       |
      |                                       |    Manually specify an IPv4 address   |                                       |
      |                                       |    to the load balancer.              |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Specification                         | -  Select either **Application load   | Medium II                             |
      |                                       |    balancing (HTTP/HTTPS)** or        |                                       |
      |                                       |    **Network load balancing           |                                       |
      |                                       |    (TCP/UDP)** or both, and then      |                                       |
      |                                       |    select the desired specification.  |                                       |
      |                                       |    You can select only one            |                                       |
      |                                       |    specification for **Application    |                                       |
      |                                       |    load balancing (HTTP/HTTPS)** and  |                                       |
      |                                       |    **Network load balancing           |                                       |
      |                                       |    (TCP/UDP)**, respectively.         |                                       |
      |                                       | -  For application load balancing,    |                                       |
      |                                       |    the number of IP addresses varies  |                                       |
      |                                       |    depending on the specification.    |                                       |
      |                                       |    You can view the number of IP      |                                       |
      |                                       |    addresses required by the load     |                                       |
      |                                       |    balancer in the infotip after the  |                                       |
      |                                       |    selected subnet.                   |                                       |
      |                                       | -  The performance of load balancers  |                                       |
      |                                       |    varies depending on the selected   |                                       |
      |                                       |    specifications. You can evaluate   |                                       |
      |                                       |    the actual traffic and select      |                                       |
      |                                       |    appropriate specifications based   |                                       |
      |                                       |    on the key metrics.                |                                       |
      |                                       | -  Dedicated load balancers have the  |                                       |
      |                                       |    following six specifications:      |                                       |
      |                                       |                                       |                                       |
      |                                       |    -  Small I                         |                                       |
      |                                       |    -  Small II                        |                                       |
      |                                       |    -  Medium I                        |                                       |
      |                                       |    -  Medium II                       |                                       |
      |                                       |    -  Large I                         |                                       |
      |                                       |    -  Large II                        |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Name                                  | Specifies the load balancer name.     | elb93wd                               |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Description                           | Provides supplementary information    | N/A                                   |
      |                                       | about the load balancer.              |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Tag                                   | Identifies load balancers so that     | -  Key: elb_key1                      |
      |                                       | they can be easily found. A tag       | -  Value: elb-01                      |
      |                                       | consists of a tag key and a tag       |                                       |
      |                                       | value. The tag key marks a tag, and   |                                       |
      |                                       | the tag value specifies the tag       |                                       |
      |                                       | content. For details about the naming |                                       |
      |                                       | specifications, see `Table            |                                       |
      |                                       | 2 <#elb_lb_000006__en-us_top          |                                       |
      |                                       | ic_0172674943_table1184315114541>`__. |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+

   

.. _elb_lb_000006__en-us_topic_0172674943_table1184315114541:

   .. table:: **Table 2** Tag naming rules

      +---------------------------------------+---------------------------------------+---------------------------------------+
      | **Item**                              | **Requirement**                       | **Example Value**                     |
      +=======================================+=======================================+=======================================+
      | Tag key                               | -  Cannot be left blank.              | elb_key1                              |
      |                                       | -  Must be unique for the same load   |                                       |
      |                                       |    balancer.                          |                                       |
      |                                       | -  Can contain a maximum of 36        |                                       |
      |                                       |    characters.                        |                                       |
      |                                       | -  Cannot contain asterisks (*),      |                                       |
      |                                       |    angle brackets (< and >),          |                                       |
      |                                       |    backslashes (\), equal signs (=),  |                                       |
      |                                       |    commas (,), vertical bars (|), or  |                                       |
      |                                       |    slashes (/).                       |                                       |
      |                                       | -  Can contain only the following     |                                       |
      |                                       |    character types:                   |                                       |
      |                                       |                                       |                                       |
      |                                       |    -  Uppercase letters               |                                       |
      |                                       |    -  Lowercase letters               |                                       |
      |                                       |    -  Digits                          |                                       |
      |                                       |    -  Special characters, including   |                                       |
      |                                       |       hyphens (-) and underscores (_) |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Tag value                             | -  Can contain a maximum of 43        | elb-01                                |
      |                                       |    characters.                        |                                       |
      |                                       | -  Cannot contain asterisks (*),      |                                       |
      |                                       |    angle brackets (< and >),          |                                       |
      |                                       |    backslashes (\), equal signs (=),  |                                       |
      |                                       |    commas (,), vertical bars (|), or  |                                       |
      |                                       |    slashes (/).                       |                                       |
      |                                       | -  Can contain only the following     |                                       |
      |                                       |    character types:                   |                                       |
      |                                       |                                       |                                       |
      |                                       |    -  Uppercase letters               |                                       |
      |                                       |    -  Lowercase letters               |                                       |
      |                                       |    -  Digits                          |                                       |
      |                                       |    -  Special characters, including   |                                       |
      |                                       |       hyphens (-) and underscores (_) |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+

#. Click **Create Now**.
#. Confirm the configuration and submit your request.

.. |image1| image:: /images/en-us_image_0241356603.png

.. |image2| image:: /images/en-us_image_0000001120894978.png

